#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l;
    map<int,int>col;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        void Bfs(int src){
            for(auto itr:l)
            {
                col[itr.first] = 3;
            }
            queue<int>q;
            q.push(src);
            int flag = 0;
            col[src] = 0;
            while (!q.empty())
            {
                /* code */
                int curr = q.front();
                q.pop();
                // col[curr] = flag%2;
                flag++;
                for(auto nbr:l[curr]){
                    if(col[nbr] == 3){
                        col[nbr] = flag%2;
                        q.push(nbr);
                        // cout<<"NBR "<<nbr<<endl;
                    }else{
                        if(col[nbr] == col[curr]){
                            // cout<<nbr<<endl;
                            cout<<"Not Bipartite"<<endl;
                            return;
                        }
                    }
                }
            }
            cout<<"Bipartite"<<endl;

            // for(auto it:col){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            
        }

        
};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    // g.addEdge(3,4);
    // g.addEdge(4,0);    
    g.Bfs(0);
    return 0;
}
