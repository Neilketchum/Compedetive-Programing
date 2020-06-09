// #define INT_MAX 10000000
// Mike found an interesting problem. In this problem you are given two integers, n and k. You
//  need to find the the maximum value of x, such that, n! % kx = 0.
// https://www.geeksforgeeks.org/legendres-formula-highest-power-of-prime-number-that-divides-n/

#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    int occ;
    int n,k;
    while(t>0){
        cin>>n>>k;
        int ans = INT_MAX;
        // Factorization
        for(int i = 2;i*i<= k;i++){
            if(k%i== 0){
                occ = 0;
                while(k%i==0){
                    occ++;
                    k = k/i;
                }
                // Firnding Powers of  i in n!
                int cnt = 0;
                long long p = i;
                while(p<=n){
                    cnt += n/p; // counting
                    p = p * i;
                }
                // cout<<cnt<<endl;
                ans = min(ans,cnt/occ);
            }    
        }
        if(k>1){
            //only prime factorial left for k
            int count = 0;
            int p = k;
            while(p<=n){
            count += n/p;
            p*=k;
            }
            ans = min(ans,count);
            if(ans == INT_MAX){
                ans = 0;
            }
        } 
         cout<<ans<<endl;
         t--;
    }   
    return 0;
}
