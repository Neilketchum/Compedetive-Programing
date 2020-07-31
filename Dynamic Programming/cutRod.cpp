#include<bits/stdc++.h>
using namespace std;
// Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller 
// than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
int cutRod(int *prices,int n){
    if(n<=0)return 0;
    int max_val = INT_MIN;
    for(int i = 0;i<n;i++)
        max_val = max(max_val,prices[i ] +  cutRod(prices,n-i-1));
    return max_val;
}
int cutRodDp(int *prices,int *dp,int n){
    if(n <= 0 ){
        return dp[0] = 0;
    }
    if(dp[n]!=0)return dp[n];
    int max_val = INT_MIN;
    for(int i =0 ;i<n;i++){
        max_val = max(max_val,prices[i] + cutRodDp(prices,dp,n-i-1));
    }
    return dp[n] = max_val;
}
int main(int argc, char const *argv[])
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int n = sizeof(prices)/sizeof(prices[0]); 
    cout<<cutRod(prices,n)<<endl;    
    int dp[100]  = {0};
    cout<<cutRodDp(prices,dp,n)<<endl;
    return 0;
}
