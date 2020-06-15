// PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr.Modi will visit.

// Input Format

// The first line contains N , no of test cases. The next lines contain two integers a and b denoting the range of country numbers.

// Constraints

// a<=1000000 & b<=1000000. N<=1000
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max_len 1000000
void prime_sieve(ll *p){
    for(ll i = 3;i<=max_len;i = i+2){
        p[i] = 1;//marking all ODd no as prime 
    }
    for(ll i = 3;i<=max_len;i+=2){
        if(p[i] == 1){
            for(ll j = i*i;j<max_len;j+=i){
                p[j] = 0;
            }
        }
    }
    p[0] = p[1] = 0;
    p[2] = 1;
    for(ll i = 1;i<=max_len;i++){
        p[i] = p[i] + p[i-1];
        // cout<<p[i]<<endl;
    }
}
int main(int argc, char const *argv[])
{
    ll p[1000009] = {0};
    prime_sieve(p);
    ll m,n;
    ll t;
    cin>>t;
    while(t>0){
        cin>>m>>n;
        if(m==0){
            cout<<p[n]-p[m]<<endl;
        }
        else
        {
             cout<<p[n]-p[m-1]<<endl;
        }
        
       
        t--;
    }
    
    return 0;
}
