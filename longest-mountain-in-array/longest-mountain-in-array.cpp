#include<iostream>
#include<vector>
using namespace std;
int longestMountain(vector<int>& arr) {
    int maxPeak = 0;
    int n = arr.size();

    for(int i = 1; i <= n - 2;){
        // ตรวจสอบว่าเป็นบนสุดของเขาหรือไม่
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            int backStep = i;
            int currentPeak = 1;
            // นับถอยหลังลงจากจุดบนสุด
            while(backStep >= 1 && arr[backStep] > arr[backStep - 1]){
                currentPeak++;
                backStep--;
            }
            //นับเดินหน้าจากจุดบนสุด
            while(i <= n - 2 && arr[i] > arr[i + 1] ){
                currentPeak++;
                i++;
            }

            maxPeak = max(maxPeak,currentPeak);
        }else{
            i++;
        }
    } 

    return maxPeak;
}
int main(){
    vector<int> arr = {2,1,4,7,3,2,5};
    
    cout<<longestMountain(arr);
    return 0;
}