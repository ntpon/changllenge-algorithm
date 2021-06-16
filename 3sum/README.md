# 3Sum

## Problem

- คำอธิบาย

  - ใช้อาเรย์ที่กำหนดให้ (nums) หาตัวเลขที่บวกกัน 3 ตัวแล้วได้ 0
  - คำตอบที่ได้มา ต้องไม่ซ้ำกัน

- สิ่งที่โจทย์ให้มา

  - vector<int> nums : ชุดของตัวเลข

- ภาพรวมของปัญหา
  - ใช้ set เพื่อเก็บข้อมูล เนื่องจากคำตอบจะต้องไม่ซ้ำกัน
  - ใช้เทคนิคการค้นหาข้อมูลที่เรียงแล้วด้วยวิธี Interpolation Search

## Solution

```c++
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  set<vector<int>> answer;
    for(int i = 0; i <= n-3; i++ ){
        int j = i + 1;
        int k = n - 1;
      while(j < k){
          int sum = nums[i] + nums[j] + nums[k];
          if(sum == 0){
              answer.insert({nums[i],nums[j],nums[k]});
              j++;
              k--;
          }
          else if(sum < 0) {
              j++;
          }
          else {
              // sum > 0
              k--;
          }
      }
  }

  vector<vector<int>> results;
  for (auto ans : answer){
      results.push_back(ans);
  }
  return results;
}

int main(){
    vector<int> nums = {-1,0,1};
    auto results =  threeSum(nums);

	for(auto result : results){
		for(auto no : result){
			cout<<no<<",";
		}
		cout<<endl;
	}
}
```

### Ref

- https://leetcode.com/problems/3sum
  `
