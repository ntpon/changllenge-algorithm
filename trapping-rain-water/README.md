# Trapping Rain Water

## Problem

- คำอธิบาย

  - ใช้อาเรย์ที่กำหนดให้ (height) เพื่อหาจำนวนน้ำที่กักเก็บได้หลังจากฝนตก

- สิ่งที่โจทย์ให้มา

  - vector<int> height : ชุดของตัวเลขที่บอกถึงระดับความสูงของกำแพงกักเก็บน้ำ

- ภาพรวมของปัญหา

  - แนวคิดเบื้องต้น : สังเกตว่า ที่จุดที่จะจะกักเก็บได้ จะเป็น ค่าที่น้อยที่สุด ของกกำแพงที่มากที่สุดของทางซ้ายและขวา เช่น 1,0,2 แบบนี้เราจะรู้เลยว่า ที่จุด 0 จะได้ min(1,2) ซึ่งจะได้ 1 เป็นน้ำที่กักเก็บได้ และอีกกรณีคือ ถ้า ฐานมันไม่ใช่เลข 0 จะต้องลบ ด้วยตัวเลขฐานมันด้วย

  - การเขียนโปรแกรม
    - สร้างอาเรย์ left, right และเก็บ 0 เป็นค่าเริ่มต้น
    - วนรอบเพื่อหาเลขที่มากที่สุด ของฝั่งซ้าย และ ฝั่งขวา
    - วนรอบบวกค่า โดยหาค่าที่น้อยที่สุด ของฝั่งซ้ายและขวาที่สร้างมา - ความสูงของตำแหน่งปัจจุบัน
      - สูตรเป็นดังนี้ min (left[i],right[i]) - height[i]

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    if(n <= 2) {
        return 0;
    }
    vector<int> heighs = height;
    vector<int> left(n,0), right(n,0);
    left[0] = heighs[0];
    right[n - 1] = heighs[n - 1];
    int num = 0;

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], height[i]);
        right[n-i-1] = max(right[n - i], heighs[n - i -1]);
    }

    for (size_t i = 0; i < n; i++)
    {
        num += min(left[i],right[i]) - heighs[i];
    }

    return num;


}


int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);

}
```

### Ref

- https://leetcode.com/problems/trapping-rain-water/submissions/
