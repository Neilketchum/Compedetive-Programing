#include<bits/stdc++.h>
using namespace std;
int minCoins(int target,int k,int *coins)
{

    if(target <= 0) return 0;
    if(target == 1)return 1;
    int deno = INT_MAX;
    for(int i = 0;i<k;i++){
        if(target - coins[i] >= 0)
            deno = min(deno,minCoins(target - coins[i],k,coins) + 1);
    }
    // cout<<deno<<endl;
    return deno;
}
int main(int argc, char const *argv[])
{
    int target;
    cin>>target;
    int coins[10] = {1,3,5,10,20,50,100,200,500,2000};
    int k = sizeof(coins)/sizeof(int);
    cout<<minCoins(target,k,coins);
    return 0;
}
