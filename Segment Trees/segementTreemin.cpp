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
int query(int *tree,int s,int e,int qs,int qe,int index){
    // Complete Overlap
    if(s>=qs && e<=qe){
        return tree[index];
    }
    // No OverLap
    if(qe < s || qs > e){
        return INT_MAX;
    }
    int mid = (s + e)/2;
    int left = query(tree,s,mid,qs,qe,index*2);
    int right =query(tree,mid+1,e,qs,qe,index*2 +1);
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
void rangeUpdate(int *tree,int s,int e,int l,int r,int inc,int index){
    if(l > e || r<s){
        return;
    }
    if(s == e){
        tree[index] += inc;
        return;
    }
    int mid = (s + e)/2;
    rangeUpdate(tree,s,mid,l,r,inc,2*index);
    rangeUpdate(tree,mid+1,e,l,r,inc,2*index + 1);
    tree[index] = min(tree[index*2],tree[index*2 + 1]);
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *tree = new int[4*n +1];
    buildTree(arr,0,n-1,tree,1);
    for(int i = 1;i<13;i++){
        cout<<tree[i]<<'\t';
    }
    cout<<endl;
    cout<<query(tree,0,n-1,0,5,1)<<endl;
    point_update(tree,0,n-1,3,10,1);
     for(int i = 1;i<13;i++){
        cout<<tree[i]<<'\t';
    }
    cout<<endl;
    cout<<query(tree,0,n-1,0,5,1)<<endl;
    rangeUpdate(tree,0,n-1,0,2,12,1);
    cout<<query(tree,0,n-1,0,5,1)<<endl;
    return 0;
}
