#include<bits/stdc++.h>
using namespace std;
struct node{
    node *lc;
    node *rc;
    int data;
};
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
        
       
    }
}
int main(int argc, char const *argv[])
{
    Treecreate();
    preOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    levelOrder_diffLine(root);
    return 0;
}
