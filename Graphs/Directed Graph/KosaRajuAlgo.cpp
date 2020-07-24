#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>l1;
    map<int,list<int>>l2;
    map<int,bool>visited1;
    map<int,bool>visited2;
    public:
        void addEdge(int x,int y){
            l1[x].push_back(y);
            l2[y].push_back(x);
        }
       
        void dfs(int cur,vector<int>&order){
            visited1[cur] = true;
            for(auto nbr:l1[cur]){
                if(!visited1[nbr]){
                    dfs(nbr,order);
                }
            }
            order.push_back(cur);
        }
        void dfs_rev(int cur){
            visited2[cur] = true;
            cout<<cur<<"\t";
            for(auto nbr:l2[cur]){
                if(!visited2[nbr]){
                    dfs_rev(nbr);
                }
            }
        }
        void kosaRaju(){
            
            for(auto itr:l1){
                visited1[itr.first] = false;
                visited2[itr.first] = false;
            }
            // First Pass
            vector<int>st;
            for(auto itr:l1){
                if(!visited1[itr.first]){
                    dfs(itr.first,st);
                }
            }
            // Second Pass
            for(int i = st.size() -1;i>=0;i--){
                if(!visited2[st[i]]){
                    cout<<"Component "<<i<<" ";
                    dfs_rev(st[i]);
                    cout<<endl;
                    }
                }
        }
};

int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 6);
    g.kosaRaju();
    return 0;
}
