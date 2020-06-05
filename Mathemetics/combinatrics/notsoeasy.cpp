// For a given find out all numbers less than disvisible by primefactors less than 20
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    ll primes[] = {2,3,5,7,11,13,17,19};
    while(t>0){
        ll n;
        cin>>n;
        ll subsets = (1<<8) -1; // total subsets 2^n -1
        ll ans = 0;
        for(ll i = 1;i<subsets;i++){
            ll denom = 1;
            ll setbits  = __builtin_popcount(i);
            
            for(ll j = 0;j<=7;j++){
                if(i&(1<<j)){
                    denom = denom * primes[j];
                }
            }

            if(setbits&1){
                ans += n/denom;
                 
            }else{
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
        t--;
    }

    return 0;
}
