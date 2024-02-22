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

class HB{
    public:
        int height;
        bool balance;

};

HB isbalanced(Node* root){
    HB p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }

    HB left=isbalanced(root->left);
    HB right=isbalanced(root->right);
    p.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance)
        p.balance=true;
    else
        p.balance=false;
    return p;
}


int main(){
    Node* root=buildTree();
    if(isbalanced(root).balance==true)
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
}
