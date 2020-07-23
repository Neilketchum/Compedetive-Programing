#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        bool isCycleUtil(int src,map<int,bool>visited){
            if(visited[src] == true){
                return true;
            }           
            // bool flag = false; 
            visited[src] = true;
            for(auto nbr:l[src]){
                if(isCycleUtil(nbr,visited)){
                    return true;
                }
            }
            return false;
        }
        void isCycle(){
                map<int,bool>visited;
                for(auto itr:l){
                    visited[itr.first] = false;
                }
                bool flag;
                for(auto cur:l){
                    visited[cur.first] = true;
                    for(auto nbr:l[cur.first]){
                        flag = isCycleUtil(nbr,visited);
                        if(flag == true){
                            cout<<"Cycle"<<endl;
                            return;
                        }
                    }
                    // for(auto itr:l){
                    //    visited[itr.first] = false;
                    // }
                    visited[cur.first] = false;
                }
                cout<<"No Cycle"<<endl;
        }

};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(1,5);
    // g.addEdge(5,6);
    // g.addEdge(4,2);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(3,0);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.isCycle();
    return 0;
}
