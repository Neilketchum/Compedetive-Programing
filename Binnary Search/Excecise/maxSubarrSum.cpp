// You are given a one dimensional array that may contain both positive and negative integers, 
// find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array
//  is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.
//  NOTE:- please solve this problem using Divide and Conquer instead of kadane's algorithm.
#include<bits/stdc++.h>
using namespace std;
int max_sub_sum(int *arr,int n){
    if(n== 1){
        return n;
    }

    int m  = n/2;

    int left = max_sub_sum(arr,m);

    int right = max_sub_sum(arr+m,n-m);

    int ans = max(left,right);

    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    
    int sum = 0;

    for(int i = m;i<n;i++){
        sum += arr[i];
        right_sum = max(sum,right_sum);
    }

    sum = 0;

    for(int i = (m - 1);i>=0;i--){
        sum+= arr[i];
        left_sum = max(left_sum,sum);
    }
    return max(ans,left_sum + right_sum);
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        cout<<max_sub_sum(arr,n)<<endl;
        t--;
    }   
//     int arr[8] = {-2, -5, 6, -2, -3, 1, 5, -6};

//    cout<<max_sub_sum(arr,7)<<endl;
    return 0;
}
