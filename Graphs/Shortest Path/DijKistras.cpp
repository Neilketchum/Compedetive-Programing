#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>>m;
    public:
        void addEdge(T u,T v,int dist,bool bidir = true){
            m[u].push_back(make_pair(v,dist));
            if(bidir)
                m[v].push_back(make_pair(u,dist));
        }
        void printAdj(){
            for(auto itr:m){
                cout<<itr.first<<" --> ";
                for(auto nbr:itr.second){
                    cout<<"("<<nbr.first<<" , "<<nbr.second<<" )  ";
                }
                cout<<endl;
            }

        }
        void Dijkistras(T src){
            map<T,int>dist;
            for(auto itr:m){
                dist[itr.first] = INT_MAX;
            }
            dist[src] = 0;
            set<pair<int,T>>s;
            s.insert(make_pair(0,src));
            while(!s.empty()){
                auto p = *(s.begin());
                T node = p.second;
                int nodeDistance = p.first;
                s.erase(s.begin());
                // Iterate Neihbours
                for(auto childPair:m[node]){
                    if(nodeDistance + childPair.second < dist[childPair.first]){
                         T dest  = childPair.first;
                         auto f = s.find(make_pair(dist[dest],dest));
                         if(f!=s.end()){
                             s.erase(f);
                         }
                         dist[dest] = nodeDistance + childPair.second;
                         s.insert(make_pair(dist[dest],dest));
                    }
                }
            }
            for(auto itr:dist){
                cout<<"Distance of "<<itr.first <<" from "<<src<<" is "<<itr.second<<endl;
            }
        }
};
int main(int argc, char const *argv[])
{
    Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    g.Dijkistras(1);
    return 0;
}
