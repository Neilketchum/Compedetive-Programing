#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n<=1){
        return n;
    }
    return n *fact(n-1);
}
int main(int argc, char const *argv[])
{
    cout<<fact(5)<<endl;
    return 0;
}
