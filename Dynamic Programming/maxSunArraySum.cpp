#include<bits/stdc++.h>
using namespace std;
int maxSubArrayDC(int *arr,int n){
    if(n == 1){
        return n;
    }
    int m = n/2;
    int left = maxSubArrayDC(arr,m);
    int right = maxSubArrayDC(arr+m,n-m);
    int left_sum = INT_MIN,right_sum = INT_MIN;
    int ans = max(left,right),sum = 0;
    for(int i = m;i<=n;i++){
        sum+= arr[i];
        right_sum = max(right_sum,sum);
    }
    sum  = 0;
    for(int i = m-1;i >=0;i--){
        sum+=arr[i];
        left_sum = max(left_sum,sum);
    }
    return max(sum,left_sum+right_sum);
}
int maxSubArrayDP(int *arr,int n){
    int dp[100] = {0};
    dp[0] = arr[0]>=0?arr[0]:0;
    int max_so_far = dp[0];
    for(int i = i;i<n;i++){
        dp[i] = dp[i-1] + arr[i];
        if(dp[i]<0){
            dp[i]  = 0;
        }
        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}
int kadaneAlgo(int *arr,int n){
    int cur_sum = 0 ;
    int max_so_far = 0;
    for(int i = 0;i<n;i++){
        cur_sum += arr[i];
        if(cur_sum<0){
            cur_sum = 0;
        }
        max_so_far = max(max_so_far,cur_sum);
    }
    return max_so_far;
}
int main(int argc, char const *argv[])
{
    int arr[10] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSubArrayDC(arr,n-1)<<endl;    
    cout<<maxSubArrayDP(arr,n)<<endl;
    cout<<kadaneAlgo(arr,n)<<endl;
    return 0;
}
