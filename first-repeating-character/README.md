# First Repeating Character

## Problem

- คำอธิบาย

  - ให้ข้อความมาไว้ใน str ให้สร้างฟังก์ชันเพื่อ return ตัวอักษรตัวแรกที่ซ้ำ ถ้าไม่มีตัวอักษรที่ซ้ำให้ return '\0'

- สิ่งที่โจทย์ให้มา

  - vector<int> str : ข้อความ

- ภาพรวมของการปัญหา
  - ใช้ set (hash) เพื่อเก็บข้อมูล เนื่องจากคำตอบจะต้องไม่ซ้ำกัน
  - การเขียนโปรแกรม
    - วนรอบ n ครั้งโดยเริ่มจากตัวอักษรตัวแรก
      - ถ้าไม่มีอักษรใน hash ให้เก็บตัวอักษรตัวที่ตรวจสอบไว้ และทำงานต่อไป
      - ถ้ามีอยู่แล้ว return ตัวอักษรตัวนั้น
    - วนจบจบ ไม่พบ return '\0'

## Solution

```c++
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

char firstRepeatingCharacter(string str){
    int n = str.size();
    unordered_set<char> setsChar;
    for (int i = 0; i < n; i++)
    {
       if(setsChar.find(str[i]) == setsChar.end()){
           setsChar.insert(str[i]);
       }else{
           return str[i];
       }
    }
    return '\0';

}

int main(){
    string str = "response";
    cout<<firstRepeatingCharacter(str);
    return 0;
}
```

### Ref

- https://www.udemy.com/course/50-problems/
