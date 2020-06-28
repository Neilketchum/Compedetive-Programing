// GCD(a,b) * LCM(a,b) = a*b;
#include<bits/stdc++.h> 
using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;
    cout<<(m*n)/gcd(m,n);
    return 0;
}
