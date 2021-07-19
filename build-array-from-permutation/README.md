# Build Array from Permutation

## Problem

- คำอธิบาย

  - ให้อาเรย์ ที่บอกค่าแต่ละตำแหน่งมา จงสร้างฟังก์ชันเพื่อส่งคืนอาเรย์ตาม ค่าที่ให้มา

- สิ่งที่โจทย์ให้มา

  - nums : arrays ที่บอกตำแหน่งของค่าที่แท้จริง

- ภาพรวมของการปัญหา
  - วนรอบจนถึง nums โดยแต่ละรอบให้เพิ่มข้อมูลตามเงื่อนไขนี้ nums[nums[i]];

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;
vector<int> buildArray(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int index = nums[i];
        ans.push_back(nums[index]);
    }
    return ans;
}
int main() {
    vector<int> nums =  {0,2,1,5,3,4};
    vector<int> ans = buildArray(nums);
    for(int num : ans){
        cout<< num <<endl;
    }
    return 0;
}
```

### Ref

- https://leetcode.com/problems/build-array-from-permutation/
