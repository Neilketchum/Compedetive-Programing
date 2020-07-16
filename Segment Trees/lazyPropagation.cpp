#include<bits/stdc++.h>
using namespace std;
int lazy[10000] = {0};
void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index)
{
    // Resolve lazy value before going down.
    if(lazy[index] != 0){
        tree[index] += lazy[index];
        // Non Leaf Node
        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1] +=lazy[index];
        }
        lazy[index] = 0;
    }
    if(ss>r or l>se){
        return; //NO overlap
    }
    if(ss>=l && se <= r){
        tree[index] += inc;
        // Create new Lazy value
        if(ss!=se){
            lazy[2*index] +=inc;
            lazy[2*index +1] += inc;
        }
        return;
    }
    // Recusrive Partial
    int mid = (ss + se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,index*2);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

void buildTree(int *a,int s,int e,int *tree,int index){
    if(s == e){
        tree[index] = a[s];
        return;
    }
    int mid = (s + e)/2;
    buildTree(a,s,mid,tree,index*2);
    buildTree(a,mid+1,e,tree,index*2 +1);
    tree[index] = min(tree[2*index],tree[2*index +1]);
}
int queryLazy(int *tree,int ss,int se,int qs,int qe,int index){
    // resolve lazy value
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(ss > qe or se < qs){
        return INT_MAX;//NO overLap
    }
    if(ss>=qs and se<=qe){
        return tree[index]; //Complete OVerlap
    }
    //Partial Overlap
    int mid =(ss + se )/2;
    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    // tree[index] = min(tree[2*index],tree[2*index +1]);
    return min(left,right);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *tree = new int[4*n +1];
    buildTree(arr,0,n-1,tree,1);
    // for(int i = 1;i<13;i++){
    //     cout<<tree[i]<<'\t';
    // }
    cout<<endl;
    updateRangeLazy(tree,0,n-1,0,2,10,1);
    updateRangeLazy(tree,0,n-1,0,4,10,1);
    cout<<"Q1 1- 1  "<<queryLazy(tree,0,n-1,1,1,1)<<endl;
    updateRangeLazy(tree,0,n-1,3,4,10,1);
    cout<<"Q2 3- 5  "<<queryLazy(tree,0,n-1,3,5,1)<<endl;

    return 0;
}
