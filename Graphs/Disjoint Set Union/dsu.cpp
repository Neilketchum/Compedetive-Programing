#include<bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int>par,size;
    int total_component;
    void init(int n){
        par.resize(n);
        size.resize(n);
        total_component = n;
        for(int i =0;i<n;i++){
            // cout<<"Hello World"<<endl;
            par[i] = i;
            size[i] = 1;
        }
    }
    int get_superparent(int x){
        if(x == par[x]){
            return x;
        }else{
            // PATH COMPRESSION
            par[x] = get_superparent(par[x]);
        }
    }
    void unite(int x,int y){
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        if(super_parent_x != super_parent_y){
            if(size[super_parent_y] > size[super_parent_x]){
                size[super_parent_y]+= size[super_parent_x];
                size[super_parent_x] = 0;
                par[super_parent_x] = super_parent_y;
            }else{
                size[super_parent_x]+= size[super_parent_y];
                size[super_parent_y] = 0;
                par[super_parent_y] = super_parent_x;
            }
            total_component--;
        }
    }
    void totalComp(){
        cout<<total_component<<endl;
    }
}g;
int main(int argc, char const *argv[])
{
    int n,m;
    // struct dsu *g;
    cin>>n>>m;
    g.init(n);
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g.unite(x,y);
    }
    // g.totalComp();
    map<int,list<int>>l;
    // vector<vector<int>>v(n,vector<int>(100,0));
    for(int i = 0;i<n;i++){
        l[i].push_back(g.get_superparent(i));
    }   
    for(auto i:l){
        for(auto child:i.second){
            if(child!=0){
                cout<<i.first<<"\t";
                cout<<child<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
