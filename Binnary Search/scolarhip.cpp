#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool canGive(ll mid,ll n,ll m,ll x,ll y){
    if(((n - mid )* y) + m >= (x * (mid))){
        // cout<<mid<<endl;
        return true;
    }else{
        return false;
    }
}
int main(int argc, char const *argv[])
{
    ll n,m,x,y,mid,s,e,ans = -1;
    cin>>n>>m>>x>>y;
    s = 0;
    e = n ;
    while (s<=e)
    {
        mid = s + (e-s)/2;
        if(canGive(mid,n,m,x,y)){
            s = mid + 1;
            ans = mid;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
