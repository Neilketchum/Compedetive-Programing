//  A---(20)---M
//  | \         |
//  | \        | 
// (10)(50)   (30) 
//  |     \    |
//  |       \  /
//  C--(40)-(D)

#include<bits/stdc++.h>
using namespace std;
class Graph{
    unordered_map<string,list<pair<string,int>>>l;
    public:
        void addEdge(string x,string y,bool bidir,int wt){
            l[x].push_back(make_pair(y,wt)); 
            if(bidir){
                l[y].push_back(make_pair(x,wt));
            }
        }
        void printAdgList(){
            for(auto p:l){
                string src = p.first;
                list<pair<string,int>>nbr = p.second;
                cout<<"Vertex "<<p.first<<" -->  ";
                for(auto it:p.second){
                    cout<<"("<<it.first<<","<<it.second<<")"<<"\t";
                }
                cout<<endl;
            }
        }
    
};
int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("C","D",true,50);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.printAdgList();
    return 0;
}
