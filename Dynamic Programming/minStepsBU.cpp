#include<bits/stdc++.h>
using namespace std;
int minSteps(int n){
    int dp[n+1]  = {0};
    dp[1] = 1;
    dp[0] = 1;
    for(int i = 2;i<=n;i++){
        int opt1 = INT_MAX,opt2  = INT_MAX,opt3 = INT_MAX;
        if( i%3==0 && n-3 > 0 ){
            opt1 = dp[i-3] + 1;
        }
        if(i%2 == 0 && n-2 > 0){
            opt2 = dp[i-2] + 1;
        }
        opt3 = dp[i-1] + 1;
        dp[i] = min(min(opt1,opt2),opt3);
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n ;
    cin>>n;    
    cout<<minSteps(n);
    return 0;
}
