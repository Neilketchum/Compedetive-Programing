#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Graph{
    map<ll,list<ll>>l;
    public: 
        void addEdge(ll x,ll y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        ll bfs_helper(ll src,map<ll,bool> &visited){
            // map<ll,bool>visited;
            visited[src] = true;
            queue<ll>q;
            q.push(src);
            ll count = 0;
             while(!q.empty()){
                ll cur = q.front();
                count++;
                q.pop();
                for(auto nbr:l[cur]){
                    if(visited[nbr] == false){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                    // cout<<nbr<<endl;
                }
            }
            return count; 
        }
        void Bfs(ll astros,ll src){
            map<ll,bool>visited;
            for(auto nbr:l){
                visited[nbr.first] = false;
            }
            visited[src] = true;
            queue<ll>q;
            q.push(src);
            vector<ll>graph_size;
            ll count = 0;
            while(!q.empty()){
                ll cur = q.front();
                count++;
                q.pop();
                for(auto nbr:l[cur]){
                    if(visited[nbr] == false){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            graph_size.push_back(count);
            for(auto itr : l){
                if(visited[itr.first] == false){
                    // cout<<itr.first<<endl;
                    ll temp = bfs_helper(itr.first,visited);
                    graph_size.push_back(temp);
                }
            }
            // for(auto it : graph_size){
            //     cout<<it<<endl;
            // }
            // cout<<"Size is ->"<<graph_size.size()<<endl;
            ll total_choice = (astros)*(astros - 1)/2;
            ll each_chance = 0;
            for(auto it:graph_size){
                each_chance += (it)*(it-1)/2;
            }
            cout<<total_choice-each_chance<<endl;
        }
};
int main(int argc, char const *argv[])
{
    Graph g;
    ll astros,pairs;

    cin>>astros>>pairs;
    
    for(ll i = 0;i<pairs;i++){
        ll x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    for(ll i = 0;i < astros;i++){
        g.addEdge(i,i);
    }    
    g.Bfs(astros,0);   
    return 0;
}
