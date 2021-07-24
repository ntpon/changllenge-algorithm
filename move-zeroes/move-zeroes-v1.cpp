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