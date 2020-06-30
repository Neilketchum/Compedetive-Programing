#include<bits/stdc++.h>
using namespace std;
#define ll long long
class point{
    public:
       ll int x;
       ll  int y;
};
class node{
    public:
        point s;
        point e;
};
point ed;
int findans(node pipe[],ll n,ll cost[],ll visited[],point presentPoint){
    ll ans = MAX_INT;
    for(ll i = 0;i<n;i++){
        if(!visited[i]){
            visited[i] = 1;
            point p;
            p.x = pipe[i].e.x;
            p.y = pipe[i].e.y;
            ans  = min(ans,cost[i] + findans(pipe,n,cost,visited,p) + abs(presentPoint.x - p.x) + abs(presentPoint.y - p.y)); 
        }
    }
    ans = min(ans,abs(presentPoint.x-ed.x)+abs(presentPoint.y-ed.y));
    return ans;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int n;
        cin>>n;
        point startPoint;
        node pipe[n];
        ll visited[n] = {0};
        cin>>startPoint.x>>startPoint.y>>ed.x>>ed.y;
        for(int i = 0;i<n;i++){
                cin>>pipe[i].s.x>>pipe[i].s.y>>pipe[i].e.x>>pipe[i].e.y;
                cin>>cost[i];
        }
        cout<<findans(pipe,n,cost,visted,startPoint)<<endl;
    }
    return 0;
}
