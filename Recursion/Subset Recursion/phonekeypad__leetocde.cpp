// // https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#include<bits/stdc++.h>
using namespace std;
char keypad[][10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
void generateString(char *in,char *out,int i,int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
  int digit = in[i] - '0';
  if(digit == 0 or digit == 1){
      generateString(in,out,i+1,j);
  }
  for(int k = 0;keypad[digit][k]!='\0';k++){
      out[j] = keypad[digit][k];
      generateString(in,out,i+1,j+1);
  }
  return;
}




int main(int argc, char const *argv[])
{
    char in[100];
    cin>>in;
    char out[1000];
    generateString(in,out,0,0);   
    return 0;
}
