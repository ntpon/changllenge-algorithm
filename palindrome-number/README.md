# Palindrome Number

## Problem

- คำอธิบาย

  - เลขจำนวนเต็มมา จงสร้างฟังก์ชันเพื่อตรวจสอบว่าเลขนั้นย้อนกลับแล้ว ยังเป็นตัวเลขเดิมหรือไม่

- สิ่งที่โจทย์ให้มา

  - int : x เลขจำนวนเต็ม

- ภาพรวมของการปัญหา
  - กรณีที่เป็นเลขติดลบ จะ return false
  - กรณีที่ x % 10 == 0 และ x != 0 return false
  - pop ค่าออกด้วยสูตร : pop = x % 10
  - เลื่อนเป็นตัวถัดไปด้วย : x /= 10
  - เราจะทำแค่ครึ่งเดียว เพราะวนซ้ำไปแค่ครึ่งเดียวเราจะรู้แล้วว่าใช่หรือไม่
    - กรณีแรก : 1221 => 12 = 12
    - กรณีที่สอง: 121 => 1 = 12/10

## Solution

```c++
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
```

### Ref

- https://leetcode.com/problems/palindrome-number/
