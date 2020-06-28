#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
    return 0;
}
