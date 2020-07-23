#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        void topologicalSort(){
            map<int,int>inDegree;
            for(auto itr:l){
                inDegree[itr.first] = 0;
            }
            for(auto itr:l){
                for(auto p:itr.second){
                    inDegree[p]++;
                }
            }
            queue<int>q;
            for(auto itr:l){
                if(inDegree[itr.first] == 0){
                    q.push(itr.first);
                }
            }
            while(!q.empty()){
                int current = q.front();
                q.pop();
                cout<<current<<"\t";
                for(auto itr:l[current]){
                    inDegree[itr]--;
                    if(inDegree[itr] == 0){
                        q.push(itr);
                    }
                }
            }
        }
};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.topologicalSort();
    return 0;
}
