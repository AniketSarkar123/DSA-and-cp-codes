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

void printKthlevel(Node *root, int k){
    if(root==NULL)
        return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);
}

void bfs(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f=q.front();
        cout<<f->data<<",";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);

    }
}

int main(){
    Node *root=buildTree();
    /*int h=height(root);
    for(int i=1;i<=h;i++){
        printKthlevel(root,i);
        cout<<endl;
    }*/
    bfs(root);


}