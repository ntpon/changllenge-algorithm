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