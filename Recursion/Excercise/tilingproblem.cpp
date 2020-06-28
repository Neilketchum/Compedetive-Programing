// Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

// Input Format
// First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
// The first line of each test case contains two integers N and M.
#include<bits/stdc++.h>
using namespace std;
int tile_recur(int n,int m){
    if(n == m){
        return 2;
    }
    if(n<m){
        return 1;
    }
    return tile_recur(n-1,m) + tile_recur(n-m,m);

}
int tile_dynamic(int n,int m){
    cout<<"hiu";
    int count[n+1];
    count[0] = 0;
    for(int i = 1;i<m;i++){
        count[i] = 1;
    }
    count[m] = 2;
    for(int i = m+1;i<=n;i++){
        count[i] = count[i-1] + count[i-m];
    }
    return count[n];
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        if(n<m){
            cout<<1<<endl;
        }
        else if(n == m){
            cout<<2<<endl;
        }
        else{
            // cout<<tile_recur(n,m)<<endl;
            cout<<tile_dynamic(n,m)<<endl;
        }
        t--;
    }
    return 0;
}
