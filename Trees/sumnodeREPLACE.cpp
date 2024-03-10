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

int replaceSUM(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int temp=root->data;
    int leftSUM=replaceSUM(root->left);
    int rightSUM=replaceSUM(root->right);
    root->data=leftSUM+rightSUM;
    return temp+root->data;


}

int main(){
    Node* root=buildTree();
    bfs(root);
    cout<<endl;
    cout<<replaceSUM(root);
    bfs(root);

}