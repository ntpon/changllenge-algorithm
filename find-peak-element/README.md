# Find Peak Element

## Problem

- คำอธิบาย

  - ให้ ชุดของตัวเลขจำนวนเต็มมา จงสร้างฟังก์เพื่อหา Peak Element โดยส่งคืนมาเป็น index ของตำแหน่ง peak
  - Peak Element คือ ตัวเลขที่มีค่ามากกว่าหรือเท่ากับทั้งตัวก่อนหน้าและตัวถัดไป

- สิ่งที่โจทย์ให้มา

  - nums : ชุดของตัวเลขจำนวนเต็มมา

- ภาพรวมของการปัญหา
  - ทั่วไปสามารถใช้ O(n) วนรอบตามเงื่อนไข arr[i-1] <= peak >= arr[i+1]
  - เราประยุกต์เรื่อง Binary Search Tree เข้ามาช่วยในการแก้ปัญหาได้ เพื่อให้ได้ O(Log n)
  - เราจะค้นหาต่อไป เมื่อ ซ้าย < ขวา อยู่
    - หาค่าตรงกลางระหว่าง ซ้าย ขวา
    - ถ้า ตัวกลาง น้อยกว่า ตัวถัดไปของมัน
      - ตัวทางซ้ายจะย้ายมา เป็นตัวถัดไป
      - ถ้าไม่ใช่ ตัวทางขวาจะย้ายมาเป็นตัวกลาง : นั้นเพราะตัวมันมากกว่าตัวทางขวาแล้วไง

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(nums[mid] < nums[mid+1]){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  return left;
}


int main () {
  vector<int> nums = {1,2,1,3,5,6,4};
  cout<<findPeakElement(nums);
}
```

### Ref

- https://leetcode.com/problems/find-peak-element/
- https://www.udemy.com/course/50-problems/
