#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {   
    int maxLength = 0;
    int start = 0;
    int indexes[127];
    int n = s.length();
    fill_n(indexes,127,-1);
    for(int i = 0; i < n; i++){
       int indexChar = (int) s[i];
      if(indexes[indexChar] >= start){ //ถ้าตัวอักษรเริ่มซ้ำ
        start = indexes[indexChar] + 1;
      }
      indexes[indexChar] = i; 
      maxLength = max(maxLength,i - start + 1);
      // i : วนรอบ - start : ตำแหน่งที่เริ่มซ้ำ -> เพื่อให้ได้ค่าปัจจุบันว่ามีกี่ตัว 
      // + 1 เพื่อให้ค่านับแต่ละรอบ
    }
    return maxLength;
}
int main() {
  string s = "au";
  cout << lengthOfLongestSubstring(s);
}