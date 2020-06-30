#include<bits/stdc++.h>
using namespace std;
string keyboard[10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [50] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
void keyres(char *input,char *output,int i,int j){
    if(input[i] == '\0'){
        output[j] = '\0';
        //  cout<<output<<endl;
        for(int i = 0;i<11;i++){
            if(searchIn[i].find(output) != std::string::npos){
                cout<<searchIn[i]<<endl;
            }
        }
        return;
    }
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
