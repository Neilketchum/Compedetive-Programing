#include<bits/stdc++.h>
using namespace std;
char keyboard[10][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void keyres(char *input,char *output,int i,int j){
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    accumulate(a.begin(), a.end(), 0)
    // cout<<keyboard[2][1]<<endl;;
    int digit = input[i] - '0';
    for(int k = 0;keyboard[digit][k]!='\0';k++){
        output[j] = keyboard[digit][k];
        keyres(input,output,i+1,j+1);
    }
}
int main(int argc, char const *argv[])
{
    char input[100];
    cin>>input;
    char output[100];
    keyres(input,output,0,0);
    return 0;
}
