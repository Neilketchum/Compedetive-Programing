#include<bits/stdc++.h>
using namespace std;
int pow(int a,int n){
    if(n == 1){
        return a;
    }
    else if(n&1){
        return a * pow(a,n/2) * pow(a,n/2);
    }
    else{
        return pow(a,n/2)  * pow(a,n/2);
    }
}

int main(int argc, char const *argv[])
{
    int a,n;
    cin>>a>>n;
    cout<<pow(a,n)<<endl;
    return 0;
}
