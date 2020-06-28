// In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

// Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

// Alice is very weak in maths section. Help her to find the number of such n digit integers.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> Multiply(vector<vector<ll>>a,vector<vector<ll>>b){
    vector<vector<ll>> C(2,vector<ll>(2));
    for(ll i = 0;i<2;i++){
        for(ll j = 0;j<2;j++){
            for(ll k = 0;k<2;k++){
                C[i][j]+= a[i][k]*b[k][j];
            }
        }
    }
    return C;
}
vector<vector<ll >> pow(vector<vector<ll>> a,ll n){
    if(n == 1){
        return a;
    }
    if(n&1){
        return Multiply(a,pow(a,n-1));
    }else{
        vector<vector<ll>>X = pow(a,n/2);
        return Multiply(X,X);
    }
}
ll getno(ll n){
    vector<vector<ll>>trans{{0,1},{1,1}};
    if(n == 0 || n == 1){
        return 1;
    }
    // cout<<"hlo";
    trans = pow(trans,n-1);
    
    return trans[1][0] * 1 + trans[1][1] * 1;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        // cout<<n;
             cout<<'#'<<n<<" : "<<getno(n+1)<<endl;
       
        t--;
    }
    
    return 0;
}
