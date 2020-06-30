#include<bits/stdc++.h>
using namespace std;
set<string>s;
void permute(char *input,int i){
    if(input[i] == '\0'){
        // output[j] = '\0';
        string t(input);
        // cout<<input<<endl;
        s.insert(t);
        return;
    }
    for(int j = i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        permute(input,i+1);
        swap(input[i],input[j]);
    }
}
int main(int argc, char const *argv[])
{
    char input[9];
    cin>>input;
    char output[10];
    permute(input,0);
    for(auto x:s){
        cout<<x<<endl;
    }

    return 0;
}