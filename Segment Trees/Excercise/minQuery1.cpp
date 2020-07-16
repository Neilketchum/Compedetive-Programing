#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int s,int e,int *tree,int index){
    if(s == e){
        tree[index] = arr[s];
        return;
    }
    int mid = (s + e)/2;
    buildTree(arr,s,mid,tree,index * 2); //Left 
    buildTree(arr,mid+1,e,tree,2*index+1);//Right
    tree[index] = min(tree[index*2],tree[index*2 +1]);
}
int get_min(int *tree,int s,int e,int qs,int qe,int index){
      if(s>=qs && e<=qe){
        return tree[index];
    }
    // No OverLap
    if(qe < s || qs > e){
        return INT_MAX;
    }
    int mid = (s + e)/2;
    int left = get_min(tree,s,mid,qs,qe,index*2);
    int right =get_min(tree,mid+1,e,qs,qe,index*2 +1);
    return min(left,right);
}
void point_update(int *tree,int s,int e,int i,int inc,int index){
    if(i < s || i > e){
        return;
    }
    if(s == e){
        tree[index] += inc;
        return ;
    }
    int mid = (s + e) /2;
    point_update(tree,s,mid,i,inc,index*2);
    point_update(tree,mid+1,e,i,inc,index*2 +1);
    tree[index] = min(tree[index*2],tree[index*2 +1]);
}
int main(int argc, char const *argv[])
{
    int nodes,queries;
    cin>>nodes>>queries;
    int node[nodes] = {0};
    for(int i =0;i<nodes;i++){
        cin>>node[i];
    }
    int *tree = new int[4*nodes +1];
    buildTree(node,0,nodes-1,tree,1);
    // for(int i =1;i<4*nodes-1;i++){
    //     cout<<tree[i]<<' ';
    // }
    // cout<<endl;
    // cout<<get_min(tree,0,nodes-1,1,5,1);
    int type;
    while(queries>0){
        
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<get_min(tree,0,nodes,l-1,r,1)<<endl;
        }
        else if(type == 2){
            int i,inc;
            cin>>i>>inc;
            point_update(tree,0,nodes-1,i-1,inc,1);
            
        }
        queries--;
    }
    
    return 0;
}