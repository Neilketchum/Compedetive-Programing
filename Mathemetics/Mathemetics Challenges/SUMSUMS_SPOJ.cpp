// // The N (1 ≤ N ≤ 50,000) cows, conveniently numbered 1, 2, …, N, are trying to learn some 
// encryption algorithms. After studying a few examples, they have decided to make one of their
//  own! However, they are not very experienced at this, so their algorithm is very simple:

// // Each cow i is given a starting number Ci (0 ≤ Ci < 90,000,000), and then all the cows 
// perform the following process in parallel:

// // First, each cow finds the sum of the numbers of the other N-1 cows. After all cows are 
// finished, each cow replaces her number with the sum she computed. To avoid very large numbers, 
// the cows will keep track of their numbers modulo 98,765,431. They told Canmuu the moose about it in November; he
//  was quite impressed. Then one foggy Christmas Eve, Canmuu came to say:

// // "Your algorithm is too easy to break! You should repeat it T (1 ≤ T ≤ 1,414,213,562) times instead." Obviously, 
// the cows were very frustrated with having to perform so many repetitions of the same boring algorithm, so after 
// many hours of arguing, Canmuu and the cows reached a compromise: You are to calculate the numbers 
// after the encryption is performed!
// Matrix Exponentaion
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 98765431
ll t,n;
vector<vector<ll>>  pow_multiply(vector< vector<ll> > A,vector< vector<ll> > B){
//    Local array to store the result 
    vector<vector<ll>> C(n,vector<ll>(n));
    for(int i = 0 ;i<n;i++ ){
        for(int j = 0 ;j<n;j++){
            for(int x = 0;x<n;x++){
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
        return pow_multiply(A,pow(A,p-1));
    }else{
       vector<vector<ll> > X = pow(A,p/2);
       return pow_multiply(X,X);
    }

}
vector<ll> multiply(vector<vector<ll>>A,vector<ll> B){
    vector<ll>C(B.size());
    for(ll i = 0;i<n;i++){
        for(int j = 0;j< n;j++){
            C[i]= (C[i]+ (A[i][j] * B[j])%MOD)%MOD;
         }
    }
    return C;
}

int main(int argc, char const *argv[])
{
    cin>>n>>t;
    vector<ll>cows(n);
    ll temp;
    for(ll i = 0;i<n;i++){
        cin>>temp;
        cows[i] = temp;
    }
    vector<vector<ll>>trans(n,vector<ll>(n));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<n;j++){
            if(i == j){
                trans[i][j] = 0;
            }else{
                trans[i][j] = 1;
            }
           
        }
        
    }
    trans = pow(trans,t);
   
   
    cows = multiply(trans,cows);
    for(int i = 0;i<n;i++){
        cout<<cows[i]<<endl;
    }
    return 0;
}
