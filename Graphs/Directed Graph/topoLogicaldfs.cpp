#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        void dfs_helper(int src,map<int,bool>&visited,list<int>&ordering){
            visited[src] = true;
            for(auto nbr:l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited,ordering);
                }
            }
            ordering.push_front(src);
            // cout<<src<<endl;
        }
        void topolgy_dfs(){
            map<int,bool>visited;
            list<int>ordering;
            for(auto itr:l){
                visited[itr.first] = false;
            }   
            for(auto itr:l){
                if(visited[itr.first] == false){
                    dfs_helper(itr.first,visited,ordering);
                }
            }
            for(auto itr:ordering){
                cout<<itr<<"\t";
            }
            cout<<endl;
        }
};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(1,5);
    // g.addEdge(5,6);
    // g.addEdge(4,2);
    g.topolgy_dfs();

    return 0;
}
