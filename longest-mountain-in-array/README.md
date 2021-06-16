# Longest Mountain in Array

## Problem

- คำอธิบาย

  - ให้อาเรย์ตั้งแต่ 3 ตำแหน่งขึ้นไป สร้างภูเขา
  - ให้เลือกจุดยอดของภูเขาที่สูงที่สุด จากนั้นส่งคืนค่า จำนวนจุด ตั้งแต่เริ่มต้นภูเขาและจนถึงจุดสิ้นสุดภูเขา

- สิ่งที่โจทย์ให้มา

  - arr<int> arr : ชุดตัวเลขสำหรับสร้างภูเขา
  - เงื่อนไข ของจุดบนสุดภูเขา
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

- ภาพรวมของปัญหา
  - แนวคิดเบื้องต้น : โจทย์ได้ให้ลักษณะของจุดบนสุดสำหรับภูเขามา คือ จุดนั้น จะต้องมากกว่า จุดข้างเคียง คือทางซ้ายและขวาเสมอ
  - การเขียนโปรแกรม
    - เริ่มต้นจากตรวจสอบ ว่าใช่จุดบนสุดของภูเขาหรือไม่
      - ถ้าใช่ นับจำนวนถอยหลัง/เดินหน้า ทางที่ลงไปได้
      - ถ้าไม่ใช่ เดินหน้า และกลับไปตรวจสอบว่าใช่จุดบนสุดหรือไม่

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;
int longestMountain(vector<int>& arr) {
    int maxPeak = 0;
    int n = arr.size();

    for(int i = 1; i <= n - 2;){
        // ตรวจสอบว่าเป็นบนสุดของเขาหรือไม่
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            int backStep = i;
            int currentPeak = 1;
            // นับถอยหลังลงจากจุดบนสุด
            while(backStep >= 1 && arr[backStep] > arr[backStep - 1]){
                currentPeak++;
                backStep--;
            }
            //นับเดินหน้าจากจุดบนสุด
            while(i <= n - 2 && arr[i] > arr[i + 1] ){
                currentPeak++;
                i++;
            }

            maxPeak = max(maxPeak,currentPeak);
        }else{
            i++;
        }
    }

    return maxPeak;
}
int main(){
    vector<int> arr = {2,1,4,7,3,2,5};

    cout<<longestMountain(arr);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/longest-mountain-in-array/
