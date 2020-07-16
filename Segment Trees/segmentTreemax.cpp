#include<bits/stdc++.h>
using namespace std;
void buildTree(int * arr,int s,int  e,int *tree,int indx){
    if(s == e){
        tree[indx] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(arr,s,mid,tree,indx*2);
    buildTree(arr,mid+1,e,tree,2*indx+1);
    tree[indx] = max(tree[2*indx],tree[2*indx+1]);
}
void rangeUpdate(int *tree,int s,int e,int qs,int qe,int inc,int index){
    if(qs>e || qe<s){
        return;
    }
    if(s  == e){
        tree[index] += inc;
        return;
    }
    int mid = (s+e)/2;
    rangeUpdate(tree,s,mid,qs,qe,inc,index*2);
    rangeUpdate(tree,mid+1,e,qs,qe,inc,2*index +1);
    tree[index] = max(tree[index*2],tree[index*2 +1]);
}
void pointUpdate(int *tree,int s,int e,int i,int inc,int index){
    if(s == e){
        tree[index]+=inc;
        return;
    }
    if(i>e || i<s){
        return;
    }
    int mid = (s+e)/2;
    pointUpdate(tree,s,mid,i,inc,index*2);
    pointUpdate(tree,mid+1,e,i,inc,2*index+1);
    tree[index] = max(tree[2*index],tree[2*index+1]);
}
int query(int *arr,int s,int e,int *tree,int qs,int qe,int index){
    // No overlap
    if(qe>=e && qs<=s){
        return tree[index];
    }
    if(qe<s || qs > e){
        return INT_MIN;
    }
    
    int mid = (s+e)/2;
    int left = query(arr,s,mid,tree,qs,qe,2*index);
    int right = query(arr,mid+1,e,tree,qs,qe,2*index+1);
    return max(left,right);
}
int main(int argc, char const *argv[])
{
    int arr[] =  {1,3,-2,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *tree = new int[4*n + 1];   
    buildTree(arr,0,n-1,tree,1);
    for(int i =0;i<=13;i++){
        cout<<tree[i]<<' ';
    }
    cout<<endl;
    cout<<query(arr,0,n-1,tree,0,3,1)<<endl;
    pointUpdate(tree,0,n-1,1,10,1);
     for(int i =0;i<=13;i++){
        cout<<tree[i]<<' ';
    }
    cout<<endl;
    cout<<query(arr,0,n-1,tree,0,3,1)<<endl;
    rangeUpdate(tree,0,n-1,3,5,10,1);
      for(int i =0;i<=13;i++){
        cout<<tree[i]<<' ';
    }
    cout<<endl;
    cout<<query(arr,0,n-1,tree,0,5,1)<<endl;
    return 0;
}
