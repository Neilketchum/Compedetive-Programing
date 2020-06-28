#include<bits/stdc++.h>
using namespace std;
#define ll long long
void prime_sieve(int *p){
    for(int i =3;i<=100000;i+=2){
        p[i] = 1; //Marking all odd nums as prime
    }
    for(ll i = 3;i<=100000;i+=2){
        if(p[i]==1){
            for(ll j = i*i;j<100000;j+=i){
                p[j] = 0;
            }
        }
    }
    // Special Cases
    p[0] = p[1] = 0; //Not prime
    p[2] = 1;//Prime
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int p[1000005] = {0};
    prime_sieve(p);
    for(int i = 0;i<n;i++){
        if(p[i] == 1){
            cout<<i<<"\t";
        }
    }
    return 0;
}
