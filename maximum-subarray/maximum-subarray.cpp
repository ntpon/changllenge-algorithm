#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int global = nums[0];
    int local = nums[0];
    int n = nums.size(); 
    for (int i = 1; i < n; i++)
    {
        local = max(nums[i], local+ nums[i]);
        global = max(global, local);
    }
    return global;
}

int main () {
    vector<int> nums = {5,4,-1,7,8};
    cout << maxSubArray(nums);
    return 0;
}