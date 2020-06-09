// Naive Method
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fact(ll n){
    ll result = 1;
    for(ll i = n;i > 1;i--){
        
        result = result * i;
       
    }

    return result;
}
int combination(ll n,ll r){
    if(n == r){
        return 1;
    }
    ll numer = 1;
    for(ll i = 0;i<  r;i++){
        numer = numer * (n-i);
    }
    ll result = numer/fact(r);
    return result;
}
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    cout<<combination(2*n,n)/(n+1)<<endl;
    return 0;
}
