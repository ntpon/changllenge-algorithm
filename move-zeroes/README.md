# Search Insert Position

## Problem

- คำอธิบาย

  - ให้อาเรย์ของเลขจำนวนเต็ม จนย้ายเลข 0 ในอาเรย์ทั้งหมดไปท้ายอาเรย์
  - ลำดับอาเรย์เหมือนเดิม
  - ให้สลับโดยใช้อาเรย์เดิมเป็นคำตอบ

- สิ่งที่โจทย์ให้มา

  - nums : arrays int ชุดของตัวเลขจำนวนเต็ม

- ภาพรวมของการปัญหา
  - กำให้ pZero คือ ตำแหน่งที่ค่าของอาเรย์เป็น 0 เริ่มต้นเป็น -1
  - วนรอบ i จนถึงตัวสุดท้าย
  - ถ้า ตัวปัจจุบันไม่ใช่ 0 ให้สลับตำแหน่งกัน swap(nums[pZero+1],nums[i]) และ pZero++

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    while(i < n && j < n){
        if (nums[j] == 0){
            j++;
        }else {
            if(j != i) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
             i++;
             j++;
        }
    }
}
int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}
```

```c++
#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int pZero = -1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]!=0){
            swap(nums[pZero+1],nums[i]);
            pZero++;
        }
    }

}
int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/move-zeroes
