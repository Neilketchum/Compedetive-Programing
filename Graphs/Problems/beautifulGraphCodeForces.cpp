#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 998244353
vector<int> ar[300001];
int col[300001] , vis[300001];
int C[2];
ll power(ll x,ll n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return x;
	}
	if(n&1){
		return x * pow(x,n/2) * pow(x,n/2);
	}else{
		return pow(x,n/2) * pow(x,n/2);
	}
}
 int dfs(int node,int c){
     vis[node] = 1;
     C[c]++;
     col[node] = c;
     for(auto child : ar[node]){
         if(vis[child] == 0){
             int code = dfs(child,c^1);
             if(code == -1){
                 return -1;
             }
         }
         else{
             if(col[child] == col[node]){
                 return -1;
             }
         }
     }
 }
int main(int argc, char const *argv[])
{
    int n,m,t,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            ar[i].clear();
            vis[i] = 0;
        }
        for(int i = 0;i<m;i++){
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        ll res = 1;
        bool flag = 1;
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                C[0] = C[1] = 0;
                int code = dfs(i,0);
                if(code == -1){
                    flag = false;
                    break;
                }
                res = (res * (power(2,C[0])+power(2,C[1])))%MOD;
            }
        }
        if(flag == false){
            cout<<0<<endl;
        }else{
            cout<<res<<endl;
        }
    }
    return 0;
}
