#include<bits/stdc++.h>
using namespace std;
void primeFactors(int n){
    vector<pair<int,int>> factors;
    // int cnt = 0;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            int count = 0;
            while(n%i == 0){
                cnt++;
                n = n/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1){
        //Whatever is left is a prime no in itself
        factors.push_back(make_pair(n,1));
    }
    for(auto p:factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }
    // return factors
}
int main(){
    int n;
    cin>>n;
    primeFactors(n);
}