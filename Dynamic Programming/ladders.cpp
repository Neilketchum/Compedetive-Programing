#include<bits/stdc++.h>
using namespace std;
int ways(int n,int k){
    if(n <= 0 ) return 1;
    int total = 0;
    // cout<<total<<endl;
    for(int i = 1;i<k;i++){
        if(n-1>=0){
            total += ways(n-i,k); 
        }
    }    
    return total;
}
int laddersMemo(int *dp,int n,int k){
    if(n == 0){
        return  dp[n] = 1;
    }
    if(dp[n]!=0)return dp[n];
    int total = 0;
    for(int i = 1;i<k;i++){
        if(n-i>=0)
            total += laddersMemo(dp,n-i,k);
    }
    return dp[n] = total;
}
//  
int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    cout<<ways(n,k)<<endl;
    int dp[1000] = {0};
    cout<<laddersMemo(dp,n+1,k)<<endl;      
    // for(int i =0;i<n;i++){
    //     cout<<dp[i]<<endl;
    // }  
    return 0;
}
