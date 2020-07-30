#include<bits/stdc++.h>
using namespace std;
int maxWine(int dp[][5],int *wines,int i,int j,int years){
    if(i>j){
        return dp[i][j] = 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    int opt1 = maxWine(dp,wines,i+1,j,years+1) +  wines[i] * years;
    int opt2 = maxWine(dp,wines,i,j-1,years+1)  +  wines[j]*years;
    return dp[i][j] = max(opt1,opt2); 
}
int main(int argc, char const *argv[])
{
    int wines[5] = {2,3,5,1,4};
    int k = sizeof(wines)/sizeof(int);
    int dp[5][5] = {0};
    cout<<maxWine(dp,wines,0,k-1,1)<<endl;     
    return 0;
}
