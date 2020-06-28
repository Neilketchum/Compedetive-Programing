#include<bits/stdc++.h>
using namespace std;
void dec(int n){
    if(n == 0){
        cout<<0<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
// void inc(int n){
//     if(n == 0){
//         cout<<10-n<<endl;
//         return;
//     }
//     cout<<10-n<<endl;
//     inc(n-1);
// }
void inc(int n){
    if(n == 0){
        cout<<n<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
    
}
int main(int argc, char const *argv[])
{
    inc(10);
    dec(10);
    return 0;
}
