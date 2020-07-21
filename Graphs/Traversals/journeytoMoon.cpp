#include<bits/stdc++.h>
using namespace std;
// The member states of the UN are planning to send 2 people to the moon.
//  They want them to be from different countries. You will be given a list of
//  pairs of astronaut ID's. Each pair is made of astronauts from the same 
// country. Determine how many pairs of astronauts from different countries they can choose from.
// For example, we have the following data on 2 pairs of astronauts, and 4 astronauts total, numbered  through .
class Graph{
    map<int,list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        int dfs_helper(int src,map<int,bool> &visited,int size){
            visited[src] = true;
            for(auto it :l[src]){
                if(!visited[it]){
                    size =  dfs_helper(it,visited,size);
                   
                }
            }
           return size + 1;
        }
        void Dfs(int src){
            map<int,bool>visited;
            int size;
            vector<int>total_size;
            for(auto it:l){
                visited[it.first] = false; 
            }
            int count = 1;
            total_size.push_back(dfs_helper(src,visited,0));
            for(auto it:l){
                if(visited[it.first] == false){
                    count++;
                    total_size.push_back(dfs_helper(it.first,visited,0));
                }
            }
            cout<<"Count = "<<count<<endl;
            for(auto it:total_size){
                cout<<it<<endl;
            }
        }
};
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
