# Implement strStr()

## Problem

- คำอธิบาย

  - ให้ string ไว้ใน haystack, needle จงสร้างฟังก์ชันเพื่อ return index แรก ของ needle ที่เราหาเจอใน haystack ถ้าไม่เจอ ให้ return -1

- สิ่งที่โจทย์ให้มา

  - string haystack : ข้อความหลัก
  - string needle : ข้อความย่อย

- ภาพรวมของการปัญหา
  - ใช้ KMP algorithm เพื่อแก้ปัญหา

## Solution

```c++
#include<iostream>
#include<vector>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    int j = 0;
    int i = 1;
    int length = 0;
    int* lpsArrays = (int*) calloc(m, sizeof(int));
    if(m > n)
        return -1;
    if(m == n)
        return haystack == needle ? 0 : -1;
    if(needle == "")
        return 0;

    //Create LPS Arrays

  while(i < m){
    if(needle[i] == needle[length])
      lpsArrays[i++] = ++length;
    else if(length > 0)
      length = lpsArrays[length-1];
    else
      lpsArrays[i++] = 0;
  }
    i = 0;
    while(i < n && j < m) {
        if(haystack[i] == needle[j]){
            j++;
            i++;
        }
        else if(j > 0) {
            j = lpsArrays[j - 1];
        }else{
            i++;
        }

    }

   return j < m ? -1 : i - j;

}

int main() {
    string haystack = "aaaa", needle = "bba";
    cout << strStr(haystack, needle);
    return 0;
}
```

### Ref

- https://leetcode.com/problems/implement-strstr/
- https://www.udemy.com/course/50-problems/
