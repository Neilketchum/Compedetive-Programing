#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
    int s = 0;
    int e= n;
    float ans = -1;
    while(s<=e){
        int  mid =(s + e)/2;
        if(mid * mid  == n ){
            ans = mid;
            return ans;
        }
        if(mid * mid < n){
            s = mid+1;
        }else{
            e = mid -1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<sqrt(n);    
    return 0;
}
