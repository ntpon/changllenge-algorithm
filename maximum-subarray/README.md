# Maximum Subarray

## Problem

- คำอธิบาย

  - ให้อาเรย์ของจำนวนเต็ม nums จงสร้างฟังก์ชัน เพื่อหาผลรวมของ subarray ที่มีค่ามากที่สุด

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ชุดของตัวเลขจำนวนเต็ม

- ภาพรวมของการปัญหา

  - Subarray คือ เซตย่อยที่ต่อเนื่องกัน
  - ใช้ Kadane’s Algorithm ในการแก้ปัญหา เพื่อให้ได้ Time Complexity เป็น O(n)
  - แนวคิดของ Kadane's คือ นำผลบวกที่ต่อเนื่องกันที่มากทีสุด มาเปรียบเทียบกับ ผลบวกต่อเนื่องของตัวปัจจุบัน

  - การเขียนโปรแกรม
    - สร้างตัวแปร global ผลบวกต่อเนื่องที่มีค่ามากที่สุด , local ผลบวกต่อเนื่องที่รวมตัวปัจจุบัน

## Solution

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int global = nums[0];
    int local = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        local = max(nums[i], local+ nums[i]);
        global = max(global, local);
    }
    return global;
}

int main () {
    vector<int> nums = {5,4,-1,7,8};
    cout << maxSubArray(nums);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/maximum-subarray/
