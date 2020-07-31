#include<bits/stdc++.h>
using namespace std;
void permute(char *arr,int i ,set<string>&s){  
    if(arr[i]=='\0'){
        s.insert(arr);
        return;
    }
    for(int j = i;arr[j]!='\0';j++){
        swap(arr[i],arr[j]);
        permute(arr,i+1,s);
        swap(arr[j],arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    char arr[100];
    cin>>arr;
    set<string>s;
    permute(arr,0,s);
    cout<<s.size()<<endl;
    for(auto itr:s){
        cout<<itr<<endl;
    }
    return 0;
}
