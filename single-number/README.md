# Single Number

## Problem

- คำอธิบาย

  - ใช้อาเรย์ที่กำหนดให้ (nums) หาตัวเลขที่ไม่ซ้ำกับเลขอื่นเลย

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ชุดของตัวเลข

- ภาพรวมของปัญหา
  - แนวคิดเบื้องต้น : เพื่อลดจำนวนรอบในการค้นหาคำตอบจะใช้แนวคิดของ hash เพื่อเก็บข้อมูลตัวเลข จากนั้นตรวจสอบว่า มีค่าอยู่แล้วหรือไม่ ถ้ามีค่ามากกว่า 1 ตัวให้ลบออก สุดท้ายจะเหลือเพียงตัวเดียวที่เก็บไว้ คือคำตอบ
  - การเขียนโปรแกรม
    - วนตรวจสอบค่าใน nums ว่าอยู่ใน hash หรือไม่
      - ถ้าใช่ ค่าใน hash ออก
      - ถ้าไม่ใช่ เพิ่มค่าลงใน hash
    - ส่งคืนค่าใน hash

## Solution

```c++
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> setsNums;

    for (int i = 0; i < n; i++)
    {
        if(setsNums.count(nums[i])){
          setsNums.erase(nums[i]);
        }else{
            setsNums.insert(nums[i]);
        }
    }

    return *setsNums.begin();
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums);
}
```

### Ref

- https://leetcode.com/problems/single-number/
