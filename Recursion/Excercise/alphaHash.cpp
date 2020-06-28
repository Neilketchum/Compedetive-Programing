// Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.
#include<bits/stdc++.h>
using namespace std;
vector<char>alphaHash;
vector<string>result;
// int flag = 0;
void generteHash(){
    alphaHash.push_back('#');
    for (char c = 'a'; c <= 'z'; ++c)
        alphaHash.push_back(c);
}
void generateRes(char *input,char *output,int index,int pos){
    if(input[index] == '\0'){
        output[pos] = '\0';
        // cout<<output<<endl;
        result.push_back(output);
        return;
    }
    int curpos = input[index] - '0';
    if(input[index+1]!='\0'){
        int nextpos = input[index+1] - '0';
        int pairsum = (curpos * 10) + nextpos;
        if(pairsum <=26){
            output[pos] = alphaHash[pairsum];
            generateRes(input,output,index+2,pos+1);
        }
    }
     output[pos] = alphaHash[curpos];
        generateRes(input,output,index+1,pos+1);
}
int main(int argc, char const *argv[])
{   
    char input[100];
    cin>>input;
    char ouput[100];
    generteHash();
    generateRes(input,ouput,0,0); 
    // cout<<result;
    cout<<'[';
    for(int i = result.size() - 1;i>=0;i--){
        if(i == 0){
            cout<<result[i]<<"]"<<endl;
        }else{
               cout<<result[i]<<", ";
        }
    }
    return 0;
}
