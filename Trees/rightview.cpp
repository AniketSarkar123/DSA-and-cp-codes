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

void rightview(Node* root, int level, int &maxlevel){
    if(root==NULL){
        return;
    }
    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
    }

    rightview(root->right,level+1,maxlevel);
    rightview(root->left,level+1,maxlevel);
}

int main(){
    Node* root=buildTree();
    int maxlevel=-1;
    rightview(root,0,maxlevel);
}
