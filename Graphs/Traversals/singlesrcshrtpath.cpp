#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void Bfs(int src){
            queue<int>q;
            map<int,int>dist;
            q.push(src);
           
            for(auto node_pair:l){
                int node = node_pair.first;
                dist[node] = INT_MAX;
            }  
             dist[src] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                // cout<<node<<"/t";
                for(auto nbr:l[node]){
                    if(dist[nbr]==INT_MAX){
                        q.push(nbr);
                        dist[nbr] = dist[node] +1;
                    }
                }
            }
            // print Distance
            for(auto node_pair :l){
                int node = node_pair.first;
                int d = dist[node];
                cout<<" Node "<<node<<" is at distance at "<<d<<endl;
            }
        }
};
int main(int argc, char const *argv[])
{

    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.Bfs(0);
    return 0;
}
