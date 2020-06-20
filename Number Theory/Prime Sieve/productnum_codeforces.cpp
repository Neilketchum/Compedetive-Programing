// You are given one integer number n. Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n or say that it is impossible to do it.

// If there are several answers, you can print any.

// You have to answer t independent test cases.

// Input
// The first line of the input contains one integer t (1≤t≤100) — the number of test cases.

// The next n lines describe test cases. The i-th test case is given on a new line as one integer n (2≤n≤109).

// Output
// For each test case, print the answer on it. Print "NO" if it is impossible to represent n as a⋅b⋅c for some distinct integers a,b,c such that 2≤a,b,c.

// Otherwise, print "YES" and any possible such representation.
#include<bits/stdc++.h>
using namespace std;
#define N 10000
int p[N] = {0};
vector<int>primes;
#define ll long long
vector<pair<int,int>>factors;
void sieve(){
    for(int i = 2;i< N;i++){
        if(p[i] == 0){//if Prime
            primes.push_back(i);
            for(int j = i;j<N;j =j+i){
                p[j] = 1;//Mark not Prime
            }
        }
    }
    // for(auto x:primes){
    //     cout<<x<<"\t";
    // }
}
void gen_factors(int n){
    for(auto x:primes){
        if(x*x > n){
            break;
        }
        if(n % x == 0){
            int count = 0;
            while(n%x == 0){
                count++;
                n = n/x;
            }
            factors.push_back(make_pair(x,count));
        }
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }
}
void genResult(int n){
    if(factors.size() >=3)
    {
        cout<<"YES"<<endl;
        int flag = 0;
        while(true){
            int temp = n/(factors[flag].first * factors[flag+1].first); 
            if(temp != factors[flag].first and temp!= factors[flag+1].first){
                cout<< factors[flag].first<<"\t";
                cout<< factors[flag+1].first<<"\t";
                cout<<temp<<endl;
                break;
            }
            else{
                flag++;
            }
        }
    }
    else if(factors.size() == 2){
          int temp = n/(factors[0].first * factors[1].first); 
            if(temp != factors[0].first and temp!= factors[1].first){
                cout<<"YES"<<endl;
                cout<< factors[0].first<<"\t";
                cout<< factors[1].first<<"\t";
                cout<<temp<<endl;
            }else{
                cout<<"NO"<<endl;
            }
    }
    else{
            if(factors[0].second >= 6){
                cout<<"YES"<<endl;
                int first =   factors[0].first;
                int second = first * first;
                int third  = n/(first * second);
                cout<<first<<"\t"<<second<<"\t"<<third<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
int main(int argc, char const *argv[])
{
    
    sieve();
    int t;
    cin>>t;
    while(t>0){
        int n ;
        cin>>n;
        gen_factors(n);
        // cout<<factors.size()<<endl;
        genResult(n);
        factors.clear();
        t--;
    }    
    return 0;
}
