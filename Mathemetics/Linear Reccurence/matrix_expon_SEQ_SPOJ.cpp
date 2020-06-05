#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
vector<ll>a,b,c;
#define MOD 100000000
vector<vector<ll>> multiply(vector<vector<ll>>A,vector<vector<ll>>B){
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i =1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            C[i][j] = 0;
            for(int x= 1;x<=k;x++){
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}



vector<vector<ll>> pow(vector<vector<ll>>A,ll p){
 
    if(p == 1){
        return A;
    }
    if(p&1){
        return multiply(A,pow(A,p-1));
    }else{
        vector<vector<ll>> X = pow(A,p/2);
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
        // cout<<F1[i]<<"\t";
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
        }
    }  

    T = pow(T,n-1);

    ll res = 0;
    for(int i = 1;i<= k;i++){
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






