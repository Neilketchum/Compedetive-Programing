#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            // l[y].push_back(x);
        }
        void Bfs(int src){
            queue<int>q;
            map<int,bool>visited;
            for(auto x:l){
                visited[x.first] = false;
            }
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto nbr:l[cur]){
                    if(visited[nbr] == true){
                        cout<<"CYCLE";
                        return;
                    }else{
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
               
            }
             cout<<"No Cycle"<<endl;
        }
};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    g.Bfs(0);
    return 0;
}
