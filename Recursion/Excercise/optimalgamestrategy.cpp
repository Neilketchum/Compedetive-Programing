// Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

// Note: The opponent is as clever as the user.

// Let us understand the problem with few examples:

// 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)
// 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
#include<bits/stdc++.h>
using namespace std;
int optimalGameStrategy(int *arr,int i,int j){
    if(i == j){
        return arr[i];
    }
    if(j == i+1){
        return max(arr[i],arr[j]);
    }
    return max(arr[i] + min(optimalGameStrategy(arr,i+1,j-1),optimalGameStrategy(arr,i+2,j))    ,   arr[j]+min(optimalGameStrategy(arr,i+1,j-1),optimalGameStrategy(arr,i,j-2)));
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<optimalGameStrategy(arr,0,n-1)<<endl;
    return 0;
}
