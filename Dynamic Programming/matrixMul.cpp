#include<bits/stdc++.h>
using namespace std;
int matrixChain(int *p,int dp[][5],int i,int j){
    if(i == j) return 0;
    if(dp[i][j]!=0)return dp[i][j];
    int k ;
    int op =  INT_MAX;
    int count;
    for(int k = i;k<j;k++){
        count = matrixChain(p,dp,i,k) + matrixChain(p,dp,k+1,j) + p[i-1]*p[k]*p[j];
        op  = min(count,op);
    }
    return  dp[i][j] = op;
 }

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[5][5] = {0};
    cout<<matrixChain(arr,dp,1,n-1)<<endl;
    return 0;
}
