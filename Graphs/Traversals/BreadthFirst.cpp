#include<bits/stdc++.h>
using namespace std;
// Level Order Traversal
template<typename T>
class Graph{
    map<T,list<T>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void Bfs(T src){
            map<T,bool>V;
            queue<T>q;
            q.push(src);
            V[src]  = true;
            // cout<<src<<" ";
            while(!q.empty()){
                T  node = q.front();
                cout<<q.front()<<" ";
                q.pop();
            
                for(auto nbr:l[node]){
                    if(!V[nbr]){
                        q.push(nbr);
                        V[nbr] = true;
                    }
                }
            }
        }
};
int main(int argc, char const *argv[])
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.Bfs(0);
    return 0;
}
