# Longest Consecutive Sequence

## Problem

- คำอธิบาย

  - ใช้อาเรย์ที่กำหนดให้ (nums) เพื่อหาจำนวน ตัวเลขที่ต่อกันเป็นลำดับ ที่มากที่สุด
  - เวลาที่ใช้ต้องเป็น O(n)

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ชุดของตัวเลข (ไม่เรียงลำดับ)

- ภาพรวมของปัญหา

  - แนวคิดเบื้องต้น : เพื่อลดจำนวนรอบในการค้นหาคำตอบจะใช้แนวคิดของ hash เพื่อเก็บข้อมูลตัวเลขทั้งหมด ทำให้เราสามารถ มองหาตัวเลขได้ด้วย O(1) จากนั้น ตรวจสอบตัวเลข ว่า เป็นตัวสุดท้ายที่น้อยที่สุดในลำดับ ถ้าใช่ ให้เริ่มนับ

  - การเขียนโปรแกรม
    - สร้าง hash จาก nums โดยมีลักษณะเป็น sets
    - ตรวจสอบภายใน hash ว่าเลขนั้น - 1 แล้วมีข้อมูลอยู่ไหม
      - ถ้าไม่มีแสดงว่า เป็นตัวน้อยสุดในลำดับ ให้ + 1 แล้ววนนับ จนกว่าจะสิ้นสุดลำดับ
      - ถ้ามี แสดงว่ายัง ไม่ใช่ตัวน้อยที่สุด ให้กลับไปตรวจสอบใหม่

## Solution

```c++
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> setsNumbers;
    int maxLength = 0;
    for(int num : nums){
        setsNumbers.insert(num);
    }

    for(int num : setsNumbers){
        int numPrev = num - 1;
        if(setsNumbers.find(numPrev) == setsNumbers.end()){
            int numChain = 0;
            int currentNumber = num;
            while(setsNumbers.find(currentNumber) != setsNumbers.end()){
                numChain++;
                currentNumber++;
            }

            if(numChain > maxLength){
                maxLength = numChain;
            }
        }
    }

    return maxLength;

}

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    cout << longestConsecutive(nums);
}
```

### Ref

- https://leetcode.com/problems/longest-consecutive-sequence/
