// https://codeforces.com/problemset/problem/846/F
// You are given an array a consisting of n positive integers. You pick two integer numbers l and r from 1 to n, 
// inclusive (numbers are picked randomly, equiprobably and independent ly). If l > r, then you 
// swap values of l and r. You have to calculate the expected value of the number of unique elements in 
// segment of the array from index l to index r, inclusive (1-indexed).

// Input
// The first line contains one integer number n (1 ≤ n ≤ 106). The second line contains n integer numbers a1, a2, ... an (1 ≤ ai ≤ 106) — elements of the array.

// Output
// Print one number — the expected number of unique elements in chosen segment.

// Your answer will be considered correct if its absolute or relative error doesn't exceed 10 - 4 — formally, the answer is correct if , where x is jury's answer, and y is your answer.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000006] = {0};
ll lastaoc[1000006] = {0};
ll ans[1000006] = {0};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i = 1;i <= n ;i++){
        cin>>a[i];
    }
    memset(ans,0,sizeof(a));
    memset(lastaoc,0,sizeof(a));
    ans[0] = 0;
    double sum = 0;
    for(ll i = 1;i<=n;i++){
        ans[i] = ans[i-1] + (i - lastaoc[a[i]]); // Unique Elements in each subset
        lastaoc[a[i]] = i;
        sum += ans[i];
    }
    double finalAns = 0.0;
    finalAns = ((2*sum)-n)/(n*n);
    cout<<fixed<<setprecision(6)<<finalAns<<endl;
    return 0;
}
