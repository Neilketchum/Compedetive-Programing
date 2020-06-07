// https://www.codechef.com/problems/DIVSUBS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005],pre[1000005],hashed[1000005];
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        memset(pre,0,sizeof(pre)); //Setting Prefix Array whole as 0
        memset(hashed,0,sizeof(hashed));
    
        for(int i = 0;i<n;i++){
            cin>>a[i];
            pre[i+1] = pre[i] + a[i];
             pre[i+1] = pre[i+1] % n;    

            hashed[pre[i+1]]++;
            cout<<hashed[pre[i+1]]<<endl;
        }
        int total_sum = 0;
        cout<<endl;
        for(int i = 0;i<=n;i++){

            if(hashed[i]>1){
                total_sum += (hashed[i] * (hashed[i] -1))/2;
            }
        }
        cout<<total_sum<<endl;
        t--;
    }
    return 0;
}
