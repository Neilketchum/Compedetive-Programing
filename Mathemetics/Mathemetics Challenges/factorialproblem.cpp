// given two integers, n and k. You need to find the the maximum value of x, 
// such that, n! % kx = 0.
// Naive
#include<bits/stdc++.h>

#define ll long long
ll fact(ll n){
    ll res = 1;
    for(int i = 2;i<=n;i++){
        res = res * i;
    }
    return res;
}
ll pow(ll n,ll p){
    if(p == 1){
        return n;
    }
    if (p== 0){
        return 1;
    }
    if(n*1){
        return pow(n,p/2) * pow(n,p/2) * n;
    }else{
        return pow(n,p/2) * pow(n,p/2);
    }
}
ll compute(ll n,ll k){
    ll x =0;
    ll max = 0;
    while(pow(k,x) < fact(n)){
        if(fact(n) % pow(k,x) == 0){
            max = x;
        }
        x ++;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    ll n,k;
    while(t>0){
        cin>>n>>k;
        cout<<compute(n,k)<<endl;
        t--;
    }    
    return 0;
}
