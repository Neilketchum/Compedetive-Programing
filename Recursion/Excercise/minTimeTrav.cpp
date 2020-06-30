#include<bits/stdc++.h>
using namespace std;
#define inf 10000000000000000
#define ll long long
class point{
    public:
    ll int x;
    ll int y;
};

class node {
    public:
    point s;
    point e;
};

point ed;

ll int findans(node pipe[],ll int n,ll int cost[],ll int visited[],point presentpoint){
    
    ll int ans=inf;
    
    for(ll int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            point p;        //point that will be reached now
            p.x=pipe[i].e.x;
            p.y=pipe[i].e.y;
            ans =  min( ans , cost[i]+findans(pipe,n,cost,visited,p)+abs(presentpoint.x - pipe[i].s.x ) + abs( presentpoint.y - pipe[i].s.y ));
            visited[i]=0;
            
            visited[i]=1;
           // point p;        // point that will be reached now
            p.x=pipe[i].s.x;
            p.y=pipe[i].s.y;
            ans =  min( ans , cost[i]+findans(pipe,n,cost,visited,p)+abs(presentpoint.x-pipe[i].e.x)+abs(presentpoint.y-pipe[i].e.y));
            visited[i]=0;
        }
    }
    ans=min(ans,abs(ed.x-presentpoint.x)+abs(ed.y-presentpoint.y));
    return ans;
    
}

int main() {
	ll int t;
	cin>>t;
    int flag = 1;
	while(t--){
	    
	    ll int n;
	    cin>>n;
	   point startpoint;
	   
	   cin>>startpoint.x>>startpoint.y>>ed.x>>ed.y;
	    
	    node pipe[n];
	    ll int cost[n]={0};
	    
	    for(ll int i=0;i<n;i++){
	        cin>>pipe[i].s.x>>pipe[i].s.y>>pipe[i].e.x>>pipe[i].e.y;
	        cin>>cost[i];
	    }
	 
	    ll int visited[n]={0};
	    cout<<'#'<<flag<<' '<<": "<<findans(pipe,n,cost,visited,startpoint)<<endl;
        flag++;
	}
}