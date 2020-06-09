// You are given an array a consisting of n positive integers. You pick two integer
//  numbers l and r from 1 to n, inclusive (numbers are picked randomly, equiprobably and independently). If l > r, then 
//  you swap values of l and r. You have to calculate the expected value of the number of unique elements in segment
//  of the array from index l to index r, inclusive (1-indexed).
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    ll a[n+2]={0},sum[n+2]={0};
    ll lastoccur[1000001];
    ll total_sum = 0;
    memset(lastoccur,sizeof(lastoccur),0);
    for(ll i = 1;i<=n;i++){
        cin>>a[i];
        sum[i] =sum[i-1] + (i - lastoccur[a[i]]);
        lastoccur[a[i]] = i;
        total_sum += sum[i];
    }
    double res = total_sum;
    res = (res * 2) - (n);
    cout<<fixed<<setprecision(6)<<res/(n*n)<<endl;
    return 0;
}