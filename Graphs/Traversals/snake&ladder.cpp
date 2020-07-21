#include<bits/stdc++.h>
using namespace std;
// Minimum no Dice THrows required to reach the dest 36 starting from src
class Graph{
     map<int,list<int>>lst;
     public:
        void addEdge(int x,int y){
            lst[x].push_back(y);
        }
        void bfs(int src,int dest){
            queue<int>q;
            map<int,int>dist;
            map<int,int>parent;
            q.push(src);
            parent[src] = src;
            for(auto node:lst){
                dist[node.first] = INT_MAX;
            }
            dist[src] = 0;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto it:lst[curr]){
                    if(dist[it]==INT_MAX){
                        // cout<<it<<endl;
                        q.push(it);
                        parent[it] = curr;
                        dist[it] = dist[curr] + 1; 
                        parent[it] = curr;
                    }
                }
            }
            // }
            // for(auto it : lst){
            //     cout<<"Node "<<it.first<<"is at a distance of "<<dist[it.first]<<" from "<<src<<endl;               
            // }
            cout<<dist[dest]<<endl;
            int temp = dest;
            while(temp!=src){
                cout<<temp<<" ";
                temp = parent[temp];
            }
            cout<<endl;
        }
        
};
int main(int argc, char const *argv[])
{
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;   

    // Add Edges
    Graph g;
    for(int i = 0; i<=37;i++){
        for(int dice = 1;dice<=6;dice++){
            int j = i + dice;
            j += board[j];
            if(j<=37){
                g.addEdge(i,j);
            }
        }
    }
    g.bfs(0,36);

    return 0;
}
