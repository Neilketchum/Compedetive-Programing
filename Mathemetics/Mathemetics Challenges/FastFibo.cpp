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
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        if(n==0){
            cout<<0<<endl;   
        }
        else if(n == 1){
            cout<<1<<endl;
            
        }
        else if(n==2){
            cout<<1<<endl;
            
        }
        else{
            vector<vector<ll>> trans{{0,1},{1,1}};
        trans = pow(trans,n-2);            // cout<<endl;
        vector<ll> f{{1,1}};
        cout<<(trans[1][0]*f[0] + trans[1][1]*f[1])%MOD<<endl; 
        }
              
        t--;
    }
    return 0;
}
