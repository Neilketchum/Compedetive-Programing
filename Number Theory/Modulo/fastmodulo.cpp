#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fastModularExp(ll a,ll b,ll MOD){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%MOD;
        }
        a  = (a * a)%MOD;
        b = b>>1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cout<<fastModularExp(5,3,100)<<endl;
    return 0;
}

