#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    vector<int>par,size;
    int total_component;
    void init(int n){
        par.resize(n);
        size.resize(n);
        total_component = n;
        for(int i = 0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    int getSuperParent(int x){
        if(x == par[x]){
            return x;
        }
        else{
            par[x] = getSuperParent(par[x]);//Path compression
        }
    }
    void unite(int x,int y){
        int super_parent_x = getSuperParent(x);
        int super_parent_y = getSuperParent(y);
        if(size[super_parent_y] > size[super_parent_x]){
            size[super_parent_y]+= size[super_parent_x];
            size[super_parent_x] = 0;
            par[super_parent_x] = super_parent_y;
        }else{
            size[super_parent_y]+= size[super_parent_x];
            size[super_parent_x] = 0;
            par[super_parent_x] = super_parent_y;
        }
    }

};
int main(int argc, char const *argv[])
{
    int n,m,glaf = 0;
    Graph g;
    cin>>n>>m;
    
    g.init(n);
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(g.getSuperParent(x) == g.getSuperParent(y)){
            cout<<"Cycle";
            glaf++;
        }else{
            g.unite(x,y);
        }
    }    
    if(glaf == 0)
        cout<<"No Cycle"<<endl;
    return 0;
}
