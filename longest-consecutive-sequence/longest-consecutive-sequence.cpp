#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> setsNumbers;
    int maxLength = 0;
    for(int num : nums){
        setsNumbers.insert(num);
    }

    for(int num : setsNumbers){
        int numPrev = num - 1;
        if(setsNumbers.find(numPrev) == setsNumbers.end()){
            int numChain = 0;
            int currentNumber = num; 
            while(setsNumbers.find(currentNumber) != setsNumbers.end()){
                numChain++;    
                currentNumber++;
            }

            if(numChain > maxLength){
                maxLength = numChain;
            }
        } 
    }

    return maxLength;
    
}

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    cout << longestConsecutive(nums);
}