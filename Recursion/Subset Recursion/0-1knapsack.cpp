#include<bits/stdc++.h>
using namespace std;

int knapsack(int *wt,int *profit,int c,int n){
    if(n == 0 or c == 0){
        return 0;
    }
    int inc  = 0,dec = 0;
    int ans;
    if(wt[n-1] <= c){
        inc = profit[n-1] + knapsack(wt,profit,c-wt[n-1],n-1);
    }
    dec = 0 + knapsack(wt,profit,c,n-1);
    ans = max(inc,dec);
    return ans;
}
int main(int argc, char const *argv[])
{
    int wt[] = {1,2,3,5,1};
    int price[] = {40,20,30,50,100};
    int capacity = 7;
    int n = 5;
    cout<<knapsack(wt,price,capacity,n);
    return 0;
}
