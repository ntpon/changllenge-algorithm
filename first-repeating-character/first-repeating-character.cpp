#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

char firstRepeatingCharacter(string str){
    int n = str.size();
    unordered_set<char> setsChar;
    for (int i = 0; i < n; i++)
    {
       if(setsChar.find(str[i]) == setsChar.end()){
           setsChar.insert(str[i]);
       }else{
           return str[i];
       }
    }
    return '\0';
    
}

int main(){
    string str = "response";
    
    cout<<firstRepeatingCharacter(str);
    return 0;
}