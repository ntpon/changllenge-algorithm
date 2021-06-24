#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int outOfArea (vector<int> nums, int i) {
    int num = nums[i];
    int lastPos = nums.size() - 1;
    if(i == 0){
        return num > nums[1];
    }
    if(i == lastPos){
        return num < nums[i - 1];
    }

    return num > nums[i + 1] || num < nums[i - 1];
} 

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) {
        return 0; 
    }

    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int num = nums[i]; 
        if(outOfArea(nums, i)) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
    }
    
    if (minVal == INT_MAX){
        return 0;
    }
     int left = 0;

    while(minVal >= nums[left]) {
        left++;
        answer++;
    } 

    int right = n - 1;
    
    while(maxVal <= nums[right]){
        right--;
    }
 
    return (right - left) + 1;
}

int main() {
    vector<int> nums ={1,2,3};
    cout << findUnsortedSubarray(nums);
     
}
