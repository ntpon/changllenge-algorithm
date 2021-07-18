#include<iostream>
using namespace std;
bool isPalindrome(int x) {
    int rev = 0;
    
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    while(rev < x){
        // เราจะทำแค่ครึ่งเดียว
        // เพราะวนซ้ำไปแค่ครึ่งเดียวเราจะรู้แล้วว่าใช่หรือไม่
        // 1221 => 12 = 12  
        // 121 => 1 = 12/10 
       rev = (rev*10) + (x % 10);
       x /= 10; 
    }
    return rev == x || (rev / 10) ==  x;
}
int main() {
    int x = 121;
    cout << isPalindrome(x);
    return 0;
}