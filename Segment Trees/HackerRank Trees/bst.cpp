#include <bits/stdc++.h>
using namespace std;
struct Node{
     Node *left,*right;
    int data;
};
struct Node *root;
Node * insert(Node * root, int data) {
        struct Node *p = root;
        struct Node *q = p;
        if(root == NULL){
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
            temp->data = data;
            temp->left = temp->right = NULL;
            root = temp;
            // cout<<"Jo"<<endl;
            return root;
        }
        while(p!=NULL){
            if(p->data > data){
                q = p;
                cout<<p->data<<endl;
                p = p->left;
            }
            else if(p->data < data){
                q = p;
                cout<<p->data<<endl;
                p = p->right;
            }
        }
        if(data > q->data){
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
            temp->data = data;
            temp->left = temp->right = NULL;
            q->right  = temp;
        }else{
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
            temp->data = data;
            temp->left = temp->right = NULL;
            q->left  = temp;
        }
        return root;

    }
    void inorder(struct Node *root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
int main() {
    // cout<<"Hi"<<endl;
    root = insert(root,10);
    insert(root,20);
    insert(root,5);
    inorder(root);
}
