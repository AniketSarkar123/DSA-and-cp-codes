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

Node* buildtreefrom_Array(int *a,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node* root=new Node(a[mid]);
    root->left= buildtreefrom_Array(a,s,mid-1);
    root->right= buildtreefrom_Array(a,mid+1,e);
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

int main(){
    int arr[]={1,2,3,4,5,6,7};
    Node* root=buildtreefrom_Array(arr,0,6);
    for(int i=1;i<=height(root);i++){
        printKthlevel(root,i);
        cout<<endl;
    }
}