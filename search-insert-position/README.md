# Search Insert Position

## Problem

- คำอธิบาย

  - ให้อาเรย์ของตัวเลขและตัวเลขเป้ามหมายมา จงสร้างฟังก์ชันเพื่อหา index ของตัวเลขเป้าหมายหากตัวเลขไม่มีอยู่ให้คืน index ที่ควรจะเป็นของตัวเลขนั้น

- สิ่งที่โจทย์ให้มา

  - nums : arrays int ชุดของตัวเลขเรียงลำดับมาให้
  - target : int ตัวเลขเป้าหมาย

- ภาพรวมของการปัญหา
  - ใช้ Binary Search Tree แก้ไขปัญหา
  - ทำซ้ำเมื่อตัวเริ่มต้น ยังน้อยกว่า ตัวสุดท้าย
    - ถ้าตัวค่ากลาง >= target แสดงว่า ตัวกลางมากไป / หรือพบแล้ว ให้ตัวสุดท้ายเท่ากับตัวกลาง
    - ตัวกลาง < กว่า target ดังนั้นแสดงว่า ตัวกลางยังน้อย ให้ตัวเริ่มต้น เท่ากับตัวกลาง + 1

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();
    while(start < end){
        int mid = (start + end) / 2;
        if (nums[mid] >= target) {
            // ถ้าตัวค่ากลาง >= target แสดงว่า ตัวกลางมากไป / หรือพบแล้ว
            // ต้องขยับตัวสุดท้ายมาเป็นตัวกลาง เพื่อให้ได้ค่าที่น้อยลง
            end = mid;
        }else{
            // ตัวกลาง < กว่า target ดังนั้นแสดงว่า ตัวกลางยังน้อย
            // ต้องขยับตัวหน้าเพิ่มเข้ามา เพื่อให้ค่าที่ได้มากขึ้น โดยขยับเป็น ตัวกลาง + 1
            // สุดท้ายแล้ว เมื่อเจอคำตอบ ค่ามัน = end แต่ถ้ามันดันมากกว่า ก็คือไม่มีคำตอบ ซึ่งเข้าเงื่อนไขแรก
            start = mid +1;
        }
    }
    return start;
}
int main() {
    vector<int> nums = {1,3,5,6};
    cout<< searchInsert(nums, 2);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/search-insert-position/
