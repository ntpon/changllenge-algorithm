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
    
    if (minVal == INT_MIN){
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if(nums[i] >= minVal && nums[i] <= maxVal){
            answer++;
        }
    }
    
    return answer;
}

int main() {
    vector<int> nums ={1,3,2,3,3};
    cout << findUnsortedSubarray(nums);
     
}
