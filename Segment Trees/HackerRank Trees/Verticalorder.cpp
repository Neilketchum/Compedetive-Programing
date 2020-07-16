#include<bits/stdc++.h>
using namespace std;
struct node{
    node *lc;
    node *rc;
    int data;
};

// 10 20 30 40 50 60 70  -1 -1 -1 -1 -1 -1 -1 -1 
struct node * root = NULL;
void Treecreate(){
    struct node *p,*t;
    int x;
    queue<struct node *> q;
    cout<<"Enter Root Value "<<endl;
    cin>>x;
    root  = (struct node *)malloc(sizeof(struct node *));
    root->data = x;
    root->lc = root->rc = NULL;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout<<"Enter Lc of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = (struct node *)malloc(sizeof(struct node *));
            t->data = x;
            t->lc = t->rc = NULL;
            p->lc = t;
            q.push(t);
        }
        cout<<"Enter Rc of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = (struct node *)malloc(sizeof(struct node *));
            t->data = x;
            t->lc = t->rc = NULL;
            p->rc = t;
            q.push(t);
        }

    }
}
void preOrder(struct node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->lc);
    preOrder(root->rc);
}
void levelOrder(struct node *root){
    queue<struct node *>q;
    struct node *p;
    
    q.push(root);
    while(!q.empty()){
        p = q.front();
        if(p->lc != NULL){
            q.push(p->lc);
        }
        if(p->rc != NULL){
            q.push(p->rc);
        }
        cout<<p->data<<'\t';
        q.pop();
    }
}
void levelOrder_diffLine(struct node *root){
    queue<struct node *>q;
    struct node *p;
    
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        p = q.front();
        if(p==NULL){
            cout<<endl;
            q.push(NULL);
            q.pop();
            if(q.front() == NULL){
                break;
            }
        }else{
            if(p->lc != NULL){
                q.push(p->lc);
             
            }
            if(p->rc != NULL){
                q.push(p->rc);
   
            }
             cout<<p->data<<'\t';    
              q.pop();
        }
        // <<Hello
       
    }
}
void getVerticalOrder(node *root,int hd,map<int ,vector<int>>&m){
    if(root == NULL){
        return;
    }
    m[hd].push_back(root->data);
    getVerticalOrder(root->lc,hd-1,m);
    getVerticalOrder(root->rc,hd+1,m);
}
void printVerticalOrder(node *root){
    map<int,vector<int>>m;
    int hd = 0;
    getVerticalOrder(root,hd,m);
    map<int,vector<int>> :: iterator it;
    for(it = m.begin();it!=m.end();it++){
        for(int i =0;i< (it->second.size());i++){
            cout<<it->second[i]<<' ';
        }
         cout<<endl;
    }
   
}
void printTopView(struct node *root){
    queue<struct node * >q;
    int h_d = 0;
    queue<int>hd;
    map<int,int>m;
    q.push(root);
    hd.push(h_d);
    struct node * p = root;
    while(!q.empty()){
        if(m.count(h_d)==0){
            m[h_d] = p->data;
        }
        if(p->lc){
            hd.push(h_d-1);
            q.push(p->lc);
        }
        if(p->rc){
            hd.push(h_d+1);
            q.push(p->rc);
        }
        q.pop();
        hd.pop();
        h_d = hd.front();
        p = q.front();
    }
    for(auto it = m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
    }
}
struct node *lca(struct node *root,int a,int b){
    while(root!=NULL){
        if(root->data  > a && root->data > b){
            root = root->lc;
        }
        else if(root->data < a && root->data < b){
            root = root->rc;
        }
        else{
            return root;
        }
    }
    return null;
}
int main(int argc, char const *argv[])
{
    Treecreate();
    preOrder(root);
    cout<<endl;
    // levelOrder(root);
    levelOrder_diffLine(root);
    cout<<endl;
    // cout<<"Hello"<<endl;
    printVerticalOrder(root);
    cout<<endl;
    printTopView(root);

    return 0;
}
