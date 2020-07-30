#include<bits/stdc++.h>
using namespace std;
int minCoins(int target,int k,int *coins)
{
    int dp[1000] = {0};
    dp[0] = 0;
    dp[1] =1;
    for (int i = 2; i <= target; i++)
    {
        int val = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if((i - coins[j])>= 0){
                val = min(val,dp[i-coins[j]] + 1);
            }
        }
        dp[i] = val;
        // cout<<dp[i]<<endl;
    }
    // cout<<dp[target]<<endl;   
    return dp[target];
}
int main(int argc, char const *argv[])
{
    int target;
    cin>>target;
    int coins[10] = {1,2,5,10,20,50,100,200,500,2000};
    int k = sizeof(coins)/sizeof(int);
    cout<<minCoins(target,k,coins)<<endl;
    return 0;
}