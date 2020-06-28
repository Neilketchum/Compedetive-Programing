#include<bits/stdc++.h>
using namespace std;
const int n = 10000000;
bitset<100000005> b;
vector<long long> primes;
void sieve(){
    b.set(); //1,1,1,1,1,1
    b[0] = b[1] = 0;
    for(long long i = 1;i<=n;i+=2)
    {
        if(b[i]){
            primes.push_back(i);
            for(long long j = i*i;j<=n;j+=i){
                b[j] = 0;
            }
        }
    }

}
int main(int argc, char const *argv[])
{
    sieve();
    for(int i = 0;i<100;i++){
        if(b[i])
            cout<<primes[i]<<"\t";
    }
    return 0;
}
