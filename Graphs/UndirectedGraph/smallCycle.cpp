#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void Bfs(int src,int n,int &ans){
    
            map<int,int>dist,parent;
            for(auto i:l){
                dist[i.first] = INT_MAX;
            }
            dist[src] = 0;
            parent[src] = src;
            queue<int>q;
            q.push(src);
           while(!q.empty()){
               int cur = q.front();
               q.pop();
               for(auto nbr:l[cur]){
                   if(dist[nbr] == INT_MAX){
                       dist[nbr] = dist[cur] + 1;
                       parent[nbr] = cur;
                       q.push(nbr);
                   }else if(parent[nbr]!=cur){
                       ans = min(ans,dist[nbr]-dist[cur]+1);
                   }
               }
           
        }
    }
};
int main(int argc, char const *argv[])
{
    Graph g; 
    int n ,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    } 
    int ans = n+1;  
    for(int i = 0;i<=n;i++){
        g.Bfs(i,n,ans);
    }
    if(ans == n+1){
        cout<<"No Cycle "<<endl;
    }else{
        cout<<"Shortest Cycle length"<<n<<endl;
    }
    return 0;
}
