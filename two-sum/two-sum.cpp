#include<iostream>
#include<vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mapsNums;
    for(int i = 0; i < nums.size(); i++){
        int currentElement = nums[i];
        int pairNum = target - currentElement;
        auto number = mapsNums.find(pairNum);
        if(number != mapsNums.end()){
            return {number->second, i};
        }
        mapsNums.insert({currentElement,i});
    }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto result =  twoSum(nums,target);
    
    if(result.size() == 0)
        cout << "No Answer";
    else
        cout << result[0] << "," << result[1] << endl;
}