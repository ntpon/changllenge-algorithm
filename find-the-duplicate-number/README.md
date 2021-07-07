# Find the Duplicate Number

## Problem

- คำอธิบาย

  - ให้อาเรย์ nums ซึ่งบรรจุตัวเลข n + 1 โดยเริ่มตั้งแต่ 1 จนถึง n ซึ่ง 1 ที่บวกมาคือตัวที่ซ้ำ ให้สร้างฟังก์ชันเพื่อหาเลขที่ซ้ำ
  - ต้องไม่ไปแก้ไขค่าใน nums
  - space time ต้องเป็น constant

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ลำดับของตัวเลขตั้งแต่ 1 - (n +1) โดยมี 1 ตัว ที่ซ้ำ

- ภาพรวมของการปัญหา
  - ใช้ทฤษฏีของ Floyd's Tortoise and Hare (Cycle Detection) มาแก้ปัญหา
  - การเขียนโปรแกรม
    - สร้างตัวแปร เต่ากับกระต่าย
      - เต่าจะตรวจค่าทีละตำแหน่ง, กระต่ายจะตรวจค่าทีละ 2 ต่ำแหน่ง
      - วนตรวจสอบ จนกระทั้งเจอค่าเดียวกัน เต่าจะกลับไปที่ตำแหน่ง 0 กระต่าจะตรวจทีละ 1
      - เจอค่าเดียวกัน นั้นคือคำตอบ

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int turtle = 0;
    int rabbit = 0;
    do {
        turtle = nums[turtle];
        rabbit = nums[nums[rabbit]];
    }while(turtle != rabbit);
   turtle = 0;
    while(turtle != rabbit) {
        turtle = nums[turtle];
        rabbit = nums[rabbit];
    }

    return rabbit;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/find-the-duplicate-number/
