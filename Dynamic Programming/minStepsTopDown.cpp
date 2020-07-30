#include<bits/stdc++.h>
using namespace std;
int minSteps(int n,int *dp){
    if(n <= 1){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int opt1 = INT_MAX,opt2 = INT_MAX,opt3 = INT_MAX;
    if(n%3==0){
        opt1 = 1 + minSteps(n/3,dp);
    }
    if(n%2 == 0){
        opt2 = 1 + minSteps(n/2,dp);
    }
    opt3  = 1 + minSteps(n-1,dp);
    return dp[n] = min(min(opt1,opt2),opt3);
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int dp[199] = {0};
    std::cout << minSteps(n,dp) << std::endl;    
    return 0;
}
