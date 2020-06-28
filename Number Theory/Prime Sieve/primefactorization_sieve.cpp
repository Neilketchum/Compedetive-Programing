#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> p(100000, 0);
vector<int> primes;
void sieve()
{
    primes.push_back(2);
    for (ll i = 3; i < 100000; i += 2)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j < 100000; j += i)
                p[j] = 1;
        }
    }
}
void primeFactors(int n){
    vector<pair<int,int>> factors;
    sieve();
    for(auto i:primes){
        if(i * i>n){
            break;
        }
        // cout<<i<<"\t";
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n = n/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1){
        //Whatever is left is a prime no in itself
        factors.push_back(make_pair(n,1));
    }
    for(auto p:factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }
    // return factors
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    primeFactors(n);
    return 0;
}
