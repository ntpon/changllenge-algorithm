#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> removeDuplicates(vector<int> arr){
    int n = arr.size();
    unordered_set<int> setsNumber;
    vector<int> arrayNumber;
    for(int number : arr){
        if(setsNumber.find(number) == setsNumber.end()){
            // ถ้าไม่เจอ
            setsNumber.insert(number);
            arrayNumber.push_back(number);
        }
    }
    return arrayNumber;
}

int main(){
    vector<int> arr = {4,2,3,2,4,4,1};
    vector<int> numbersNotDuplicates = removeDuplicates(arr);
    for(int num : numbersNotDuplicates){
        cout << num <<endl;
    }
    return 0;
}