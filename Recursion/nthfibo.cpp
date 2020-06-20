//Using Recursiom Best way is still matrix expo
#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}
int main(int argc, char const *argv[])
{
    cout<<fibo(7)<<endl;
    return 0;
}
