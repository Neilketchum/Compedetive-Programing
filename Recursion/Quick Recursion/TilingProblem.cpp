// Given a wall of size of 4 * n and tiles of size(1,4) and (4,1) 
// How many ways you could u build the wall
// f(n) = f(n-4) + f(n-1)
#include<bits/stdc++.h>
using namespace std;
int recurtile(int n){
    if(n <=3){
        return 1;
    }
    return recurtile(n-4) + recurtile(n-1);
}
vector<vector<int>> multiply(vector<vector<int>>a,vector<vector<int>>b){
     vector<vector<int>>c(4,vector<int>(4));
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            for(int k =0;k<4;k++){
                c[i][j] =(c[i][j] + (a[i][k] * b[k][j])); 
            }
        }
    }
    return c;
}
vector<vector<int>> pow(vector<vector<int>>arr,int n){
    if(n <= 1){
        return arr; 
    }
    if(n&1){
        return multiply(arr,pow(arr,n-1));
    }else{
        vector<vector<int>> X = pow(arr,n/2);
        return multiply(X,X);
    }
}
int matrixrecur(int n){
    vector<vector<int>> trans{{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,0,0,1}};
    if(n<=3){
        return 1;
    }
    if(n == 4){
        return 2;
    }
    trans = pow(trans,n-1);
    //   trans = pow(trans,n-3);
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         cout<<trans[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    vector<int>f1 = {1,1,1,1};
    return trans[3][0]*1 + trans[3][3]*2 + trans[3][1]*1 +trans[3][2]*1 ;
}
int dynamic(int n){
    if(n < 4){
        return 1;
    }
    int T[n+1];
    T[1] = T[2] = T[3] = 1;
    T[4] = 2;
    for(int i=5;i<=n;i++){
        T[i] = T[i-4] + T[i-1];
    }
    return T[n];
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<recurtile(n)<<endl;
    cout<<matrixrecur(n)<<endl;
    cout<<dynamic(n)<<endl;
  
    return 0;
}
