#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int turtle = 0;
    int rabbit = 0;
    do {
        turtle = nums[turtle];
        rabbit = nums[nums[rabbit]];
    }while(turtle != rabbit);
   turtle = 0;
    while(turtle != rabbit) {
        turtle = nums[turtle];
        rabbit = nums[rabbit];
    }

    return rabbit;
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums);
    return 0;
}