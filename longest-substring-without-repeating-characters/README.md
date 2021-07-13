# Invert Binary Tree

## Problem

- คำอธิบาย

  - ให้ string มา จงสร้างฟังก์ชันที่ ส่งความยาวของ string ย่อยที่ไม่มีตัวอักษรซ้ำ
  - อย่าลืมว่ามันเป็น substring นะ เพราะงันเราจะข้ามไปไม่ได้

- สิ่งที่โจทย์ให้มา

  - string : s ข้อความที่เป็นอักษรทั้งหมด

- ภาพรวมของการปัญหา
  - วนสร้างอาเรย์ตัวอักษร 128 ตำแหน่ง ตามรหัสแอสกี้ และให้ทุกค่ามีค่าเริ่มต้นคือ - 1 คือยังไม่มีการเข้ามาตรวจสอบว่าซ้ำ
  - วนรอบเช็คทีละตัวใน string
  - ถ้ามีค่าอยู่ใน index ให้เริ่มต้นนับตำแหน่งของมัน เท่ากับค่าที่บันทึกไว้
  - ทำการบันทึกตำแหน่งลง index ว่าอยู่ตัวที่เท่าไหร่ของ str
  - ตรวจสอบหาค่ามากที่สุดกับ (i - start + 1)

## Solution

```c++
#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int start = 0;
    int indexes[127];
    int n = s.length();
    fill_n(indexes,127,-1);
    for(int i = 0; i < n; i++){
       int indexChar = (int) s[i];
      if(indexes[indexChar] >= start){ //ถ้าตัวอักษรเริ่มซ้ำ
        start = indexes[indexChar] + 1;
      }
      indexes[indexChar] = i;
      maxLength = max(maxLength,i - start + 1);
      // i : วนรอบ - start : ตำแหน่งที่เริ่มซ้ำ -> เพื่อให้ได้ค่าปัจจุบันว่ามีกี่ตัว
      // + 1 เพื่อให้ค่านับแต่ละรอบ
    }
    return maxLength;
}
int main() {
  string s = "au";
  cout << lengthOfLongestSubstring(s);
}
```

### Ref

- https://leetcode.com/problems/longest-substring-without-repeating-characters
- https://www.udemy.com/course/50-problems/
