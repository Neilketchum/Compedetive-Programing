#include<bits/stdc++.h>
using namespace std;
int minSteps(int n){
    if(n == 1 || n<=0){
        return 1;
    }
    int opt1 = INT_MAX, opt2 = INT_MAX, opt3 = INT_MAX;
    if(n%3 == 0){
        opt1 = minSteps(n/3) + 1;
    }
    if(n%2 == 0){
        opt2 = minSteps(n/2) + 1;
    }
    opt3 =  minSteps(n-1) + 1;
    return min(min(opt1,opt2),opt3);
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<minSteps(n);    
    return 0;
}
