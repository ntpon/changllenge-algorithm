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