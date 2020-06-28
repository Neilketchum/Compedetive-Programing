#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>>c(2,vector<ll>(2));
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            for(int k =0;k<2;k++){
                c[i][j] =(c[i][j] + (a[i][k] * b[k][j])%MOD)%MOD; 
            }
        }
    }
    return c;
}
vector<vector<ll>> pow(vector<vector<ll>> arr,ll n){
    if(n==1){
        return arr;
    }
    if(n&1){
        return multiply(arr,pow(arr,n-1));
    }else{
        vector<vector<ll>> X = pow(arr,n/2);
        return multiply(X,X);
    }
}
ll compute(ll n){
    if(n == 0){
        return 0;
    }if(n <=2){
        return 1;
    }
    vector<vector<ll>> t{{0,1},{1,1}};
    vector<ll> f{{1,1}};
    t= pow(t,n-2);
    return (t[1][0]*f[0] + t[1][1]*f[1])%MOD;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    ll m,n;
    while(t>0){
        cin>>m>>n;
       
        ll res = compute(m+1)%MOD;
        
        ll res1 = compute(n+2)%MOD;
       
        cout<<(res1 -res)%MOD<<endl;
        t--;
    }
    return 0;
}
