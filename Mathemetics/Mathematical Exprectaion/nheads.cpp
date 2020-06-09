// What is the expected no of coin flips to get n consective  heads
#include<bits/stdc++.h>
using namespace std;
int pow(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    if(n&1){
        return 2 * pow(n-1);
    }else{
        return pow(n/2)*pow(n/2);
    }
}
int main(int argc, char const *argv[])

{
    int n;
    cin>>n;
    cout<<(pow(n+1) -2)<<endl;  //Solving the mathemetical expection
    return 0;
}
