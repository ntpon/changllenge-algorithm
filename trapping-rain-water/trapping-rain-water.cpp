#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    if(n <= 2) {
        return 0;
    }
    vector<int> heighs = height;
    vector<int> left(n,0), right(n,0);
    left[0] = heighs[0];
    right[n - 1] = heighs[n - 1]; 
    int num = 0;
    
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], height[i]);
        right[n-i-1] = max(right[n - i], heighs[n - i -1]);     
    }
    
    for (size_t i = 0; i < n; i++)
    {
        num += min(left[i],right[i]) - heighs[i];
    }
    
    return num;


}


int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);

}