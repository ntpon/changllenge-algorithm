# Remove Duplicates

## Problem

- คำอธิบาย

  - ให้อาเรย์ ของตัวเลขไว้ใน arr ให้สร้างฟังก์ชันเพื่อ return array โดยค่าในอาเรย์นั้นจะต้องไม่ซ้ำกัน

- สิ่งที่โจทย์ให้มา

  - vector<int> arr : ชุดของตัวเลข

- ภาพรวมของการปัญหา
  - ใช้ set (hash) เพื่อเก็บข้อมูล เนื่องจากคำตอบจะต้องไม่ซ้ำกัน
  - การเขียนโปรแกรม
    - วนรอบ n ครั้งโดยเริ่มจากตัวเลขตัวแรก
      - ถ้าไม่มีอักษรใน hash ให้เก็บตัวอักษรตัวที่ตรวจสอบไว้ และทำงานต่อไป
      - ถ้ามีอยู่แล้ว return ตัวอักษรตัวนั้น

## Solution

```c++
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){
    int n = arr.size();
    unordered_set<int> setsNumber;
    vector<int> arrayNumber;
    for(int number : arr){
        if(setsNumber.find(number) == setsNumber.end()){
            // ถ้าไม่เจอ
            setsNumber.insert(number);
            arrayNumber.push_back(number);
        }
    }
    return arrayNumber;
}

int main(){
    vector<int> arr = {4,2,3,2,4,4,1};
    vector<int> numbersNotDuplicates = removeDuplicates(arr);
    for(int num : numbersNotDuplicates){
        cout << num <<endl;
    }
    return 0;
}
```

### Ref

- https://www.udemy.com/course/50-problems/
