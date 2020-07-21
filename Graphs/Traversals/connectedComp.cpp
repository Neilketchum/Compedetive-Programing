#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void dfs_helper(int src,map<int,bool> &visited){
            visited[src] = true;
            // cout<<src<<"\t";
           for(auto nbr : l[src]){
               if(!visited[nbr]){
                   dfs_helper(nbr,visited);
               }
           } 
        }
        void Dfs(int src){
            int count  = 1;
            map<int,bool>visited;
            for(auto itr:l){
                visited[itr.first] = false;
            }
            dfs_helper(src,visited);
            for(auto itr:l){
                if(visited[itr.first] == false){
                    count++;
                    dfs_helper(itr.first,visited);
                }
            }
            cout<<count<<endl;
        }

};
// How many connected componenets are present
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);

    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);

    g.Dfs(0);   
    return 0;
}
