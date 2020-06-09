// tell if there exists four numbers A[i1],A[ i2], A[i3],A[ i4] such that xor 
// of these numbers is equal to 0.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    int a[n+1] = {0};
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(n>=132){
        cout<<"YES"<<endl;
        return 0;
    }else{
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    for(int l = k+1;l<n;l++){
                        if((a[i]^a[j]^a[k]^a[l]==0)){
                            cout<<"YES"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
