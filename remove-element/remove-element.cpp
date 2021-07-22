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