#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int arr[100001];
class node{
    public:
    ll data;
    ll smallestAmong;
    node(){
        data = INT_MAX;
        smallestAmong = 0;
    }
};

class SegTree {
    public:
    vector<node>tree;

    SegTree(int n){
        tree.resize(4*n+5);
    }

    void buildtree(ll ss, ll se,ll index){

        if(ss==se){
            tree[index].data = arr[se];
            tree[index].smallestAmong = 1;
        //cout<<tree[index].smallestAmong<<endl;
            return;
        }
        node t = tree[index];
        ll mid = ss + (se-ss)/2;

        buildtree(ss,mid,2*index);
        buildtree(mid+1,se,2*index+1);
        node t1 =tree[2*index];
        node t2 = tree[2*index+1];
        t.data = min(t1.data,t2.data);
        t.smallestAmong = t1.smallestAmong + t2.smallestAmong;
       // cout<<"for range:"<<ss<<" and " <<se<<":"<<t.smallestAmong<<endl;
        tree[index]=t;
        return;
    }

    ll query(ll ss, ll se, ll l, ll r,ll value, ll index){
        if(ss>r || se<l || l>r){
            return 0;
        }

        if(ss>=l && se<=r){
            node t = tree[index];
            if(t.data>=value){
                int val = t.smallestAmong;
                //cout<<"val:"<<val<<endl;
                return val;
            }
            // return 0;
        }

        ll mid = ss + (se-ss)/2;

        ll left = query(ss,mid,l,r,value,2*index);
        ll right = query(mid+1,se,l,r,value,2*index+1);
        return left+right;
    }
};

int main() {
  int n;
  cin>>n;
  for(ll i=0;i<n;i++)  cin>>arr[i];
  ll q;
  cin>>q;
  SegTree s(n);
  s.buildtree(0,n-1,1);
  while(q--){
      ll L,R,K;
      cin>>L>>R>>K;
      cout<<s.query(0,n-1,L-1,R-1,K,1)<<endl;
  }
  return 0;
}
