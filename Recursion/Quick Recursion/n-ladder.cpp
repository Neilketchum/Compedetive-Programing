// For a n step ladder one can take 1,2or,3 steps to reach the top/Find total ways to reach the top
#include<bits/stdc++.h>
using namespace std;
int recur(int n){
    if(n == 0){
        return 1;
    }
    if(n< 0){
        return 0;
    }
    return recur(n-1) + recur(n-2) + recur(n-3);

}
int dynamic(int n){
    int temp[n+1];
    temp[0] = 1;
    temp[1] = 1;
    temp[2] = 2;
    temp[3] = 4;
    for(int i = 4;i<=n;i++){
        temp[i] = temp[i-1] + temp[i-2] + temp[i-3];
    }
    return temp[n];
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<recur(n)<<endl;
    cout<<dynamic(n)<<endl'
    return 0;
}
