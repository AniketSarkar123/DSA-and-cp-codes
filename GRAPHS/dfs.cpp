#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

vector<int> g[N];
bool vis[N]={0};

void dfs(int v){
    
    if(vis[v]==1)
        return;
    cout<<v<<endl;
    vis[v]=1;
    for(auto child:g[v]){
        cout<<"parent: "<<v<<" "<<"child: "<<child<<endl;
        dfs(child);
    }
}

int main(){
    int m,n;
    cout<<"Enter number of vertices and number of edges: ";
    cin>>m>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(k);
}