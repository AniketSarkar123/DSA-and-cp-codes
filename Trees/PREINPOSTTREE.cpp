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

void printPRE(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printPRE(root->left);
    printPRE(root->right);
}

void printIN(Node *root){
    if(root==NULL)
        return;
    printIN(root->left);
    cout<<root->data<<" ";
    printIN(root->right);
}

void printPOST(Node *root){
    if(root==NULL)
        return;
    printPOST(root->left);
    printPOST(root->right);
    cout<<root->data<<" ";
}

int height(Node *root){
    if(root==NULL)
        return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}



int main(){
    Node *root=buildTree();
    printPRE(root);
    cout<<endl;
    printIN(root);
    cout<<endl;
    printPOST(root);
    cout<<endl;
    cout<<height(root)<<endl;
    



}