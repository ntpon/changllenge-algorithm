#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> setsNums;
    
    for (int i = 0; i < n; i++)
    {   
        if(setsNums.count(nums[i])){
          setsNums.erase(nums[i]);
        }else{
            setsNums.insert(nums[i]);
        }
    }

    return *setsNums.begin();
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums);
}