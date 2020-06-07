/*
https://www.spoj.com/problems/SEQ/
Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.

Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)

Output
Exactly C lines, one for each test case: an modulo 10^9
*/
#include <bits/stdc++.h>
using namespace std;
#include <vector>
#define ll long long
#define MOD 1000000000
ll k;
vector<ll> a,b,c;
vector<vector<ll>>  multiply(vector< vector<ll> > A,vector< vector<ll> > B){
//    Local array to store the result 
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i = 1 ;i<=k;i++ ){
        for(int j = 1 ;j<=k;j++){
            for(int x = 1;x<=k;x++){
                // cout<<B[i][j]<<endl;
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD; 
            }
        }
    }

   return C; 
} 
vector< vector<ll> > pow(vector< vector<ll> > A,ll p){
    
    if(p == 1){
        return A;
    }
    if(p&1){
        return multiply(A,pow(A,p-1));
    }else{
       vector<vector<ll> > X = pow(A,p/2);
       return multiply(X,X);
    }

}
ll compute(int n)
{
    if(n == 0){
        return 0;
    }
    if(n <= k){
        return b[n-1];
    }
    // Otherwise compute Using Matrix Exponenation
    vector <ll> F1(k+1); //Indexing from 1

    for(int i = 1;i <= k ; i++){
        F1[i] = b[i-1];

    }
  
    // Building Transformation Matrix
    vector<vector<ll>> T(k+1,vector<ll>(k+1));//Using 2d Vector

    for(int i =1;i<= k;i++){
        for(int j = 1;j<= k;j++){
            if(i<k){
                if(j == i+1){
                    T[i][j] = 1;
                }else{
                    T[i][j] = 0;
                }
            }else{
                T[i][j] = c[k-j]; // Last row as reversed Coeficients
            }
            cout<<T[i][j]<<"\t"  ;
            cout<<i<<"\t\t"<<j<<"\t";
        }
        cout<<endl;
    }  

    T = pow(T,n-1);
    

    ll res = 0;
    for(int i = 1;i<= k;i++){
        cout<<T[1][i]<<F1[i]<<endl;
        res= (res+ (T[1][i] * F1[i])%MOD)%MOD;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ll t,n,num;
    cin>>t;
    while(t>0){
        cin>>k;
        for(int i = 0;i<k;i++){
            cin>>num;
            b.push_back(num);
        }
        for(int j = 0;j<k;j++){
            cin>>num;
            c.push_back(num);
        }
        cin>>n;

        cout<<compute(n)<<endl;
        b.clear();
        c.clear();
        t--;
    }
    return 0;
}

