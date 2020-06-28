#include<bits/stdc++.h>
using namespace std;
vector<int>result(33);
void generate(int n){
    result[0] =2;
    result[1]= 2;
    result[2] =2;
    result[3] = 4;
    for(int i = 4;i<=32;i++){
        result[i] = result[i-1] + (i-1)*result[i-2];
    }
}
int main(int argc, char const *argv[])
{
    generate(32);
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        cout<<result[n]<<endl;      
        t--;
    }
    return 0;
}