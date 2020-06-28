#include<bits/stdc++.h>
using namespace std;
#define N = 10000
int p[100000] = {0};
vector<int>primes;
void sieve(){
    for(int i = 2;i< 100;i++){
        if(p[i] == 0){//if Prime
        primes.push_back(i);
            for(int j = i;j<100;j =j+i){
                p[j] = 1;//Mark not Prime
            }
        }
    }
    // for(auto x:primes){
    //     cout<<x<<"\t";
    // }
}
int no_divisors(int n){
    int ans = 1;
    for(auto x:primes){
        // cout<<x<<endl;
        if(x*x  > n){
            break;
        }
        int cnt = 0;
        if(n%x == 0){
            while(n%x == 0){
                cnt+=1;
                n = n/x;
            }
            // cout<<x<<cnt<<endl;
            ans = ans*(cnt+1);
        }
    }
    if(n!=1){
        ans =ans * (2);//Prime no left
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    sieve();
    int n;
    cin>>n;
    cout<<no_divisors(n)<<endl;
    return 0;
}
