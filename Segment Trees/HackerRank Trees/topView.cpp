#include<bits/stdc++.h>
using namespace std;
struct node {
    struct node *lc,*rc;
    int data,hd;
};

// 10 20 30 40 50 60 70  -1 -1 -1 -1 -1 -1 -1 -1 
struct node* new_node(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    temp->lc = temp->rc = NULL;
    temp->data = data;
    temp->hd = INT_MAX;
    return temp;
}
void printTopView(node *root){
    if(root == NULL){
        return;
    }
    queue<struct node *>q;
    map<int,int>m;
    int hd = 0;
    root->hd = 0;
    q.push(root);
    while(!q.empty()){
        hd = root->hd;
        if(m.count(hd)==0){
            m[hd] = root->data;
        }
        if(root->lc){
            root->lc->hd = root->hd -1;
            q.push(root->lc);
        }
        if(root->rc){
            root->rc->hd = root->hd+1;
            q.push(root->rc);
        }
        q.pop();
        root = q.front();
    }
    for(auto i = m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
     node* root = new_node(1); 
    root->lc = new_node(2); 
    root->rc = new_node(3); 
    root->lc->rc = new_node(4); 
    root->lc->rc->rc = new_node(5); 
    root->lc->rc->rc->rc = new_node(6); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    printTopView(root); 
    return 0;    
    return 0;
}
