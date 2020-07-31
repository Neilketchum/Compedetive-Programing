#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int n,int src,vector<vector<int>>edges){
    vector<int>dis(n+1,INT_MAX);
    dis[src] = 0;
    // Relax Edges
    for(int i =0;i<n-1;i++){
        for(auto x:edges){
            int from = x[0],to = x[1],weight = x[2];
            if( dis[from]!=INT_MAX && dis[to]>dis[from] + weight){
                dis[to] = dis[from] + weight;
            }
        }
    }
    // For Negative Cycle
        for(auto x:edges){
            int from = x[0],to = x[1],weight = x[2];
            if( dis[from]!=INT_MAX && dis[to]>dis[from] + weight){
                // dis[to] = dis[from] + weight;
                cout<<"Negative Weight Cycle"<<endl;
                exit(0);
            }
        }
    return dis;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i = 0;i<m;i++){
        int to,from,weight;
        cin>>from>>to>>weight;
        edges.push_back({from,to,weight});
    }    
    vector<int>res = bellmanFord(n,1,edges);
    for(int i = 1;i<=n;i++){
        cout<<"Distance From "<<i<<" to src is "<<res[i]<<endl;
    }    
    return 0;
}
