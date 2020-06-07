#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    /* code */
    ll n,val;
    unsigned ll a[140];
    cin>>n;

    if(n>=140){
        cout<<"Yes"<<endl;
        return 0;
    }
    for(int i = 0;i<n;i++){
        cin>>a[i];
        
    }
    
        for(int i =0;i<n;i++){
            for(int j = i+1;j< n;j++){
                for(int k = j+1;k< n;k++){
                    for(int l = k+1;l<n;l++){
                        if((a[i] ^ a[j] ^ a[k] ^ a[l]) == 0){
                            cout<<"Yes"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
                    
             
    
    cout<<"No"<<endl;

    return 0;
}
