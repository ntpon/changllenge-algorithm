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