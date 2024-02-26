#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node* root= new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

int height(Node *root){
    if(root==NULL)
        return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

int diameter(Node* root){
    if(root==NULL)
        return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    int dia=max(op1,max(op2,op3));
    return dia;

}

class PAIR{
    public:
        int height;
        int diameter;

};

PAIR optidiameter(Node*root){
    PAIR p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    PAIR left=optidiameter(root->left);
    PAIR right=optidiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;


}

int main(){
    Node* root=buildTree();
    //cout<<diameter(root);
    PAIR p=optidiameter(root);
    cout<<p.diameter;
    
}