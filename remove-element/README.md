# Remove Element

## Problem

- คำอธิบาย

  - ให้อาเรย์ของตัวเลขและตัวเลขเป้ามหมายมา จงสร้างฟังก์ชันเพื่อลบค่าตัวเลขในอาเรย์ตามตัวเลขเป้าหมายที่ให้มา

- สิ่งที่โจทย์ให้มา

  - nums : arrays int ชุดของตัวเลข
  - val : int ตัวเลขเป้าหมาย

- ภาพรวมของการปัญหา
  - วนรอบตรวจสอบแต่ละค่า
  - เมื่อเจอตัวเลขเป้าหมายให้สลับกับตัวท้ายสุดของอาเรย์ และลดจำนวน length ของการวนรอบลง
  - ทำจนซ้ำจนรอบปัจจุบัน >= length ของ array

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int i = 0;
    while(i < n)
    {
        if(nums[i] == val){
            nums[i] = nums[n-1];
            n--;
        }else{
            i++;
        }
    }
    return n;
}
int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout<< removeElement(nums, 2);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/remove-element/
