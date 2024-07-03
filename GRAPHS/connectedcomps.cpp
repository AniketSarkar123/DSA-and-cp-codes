#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> g[N];
bool vis[N]={0};

void dfs(int v,int c,vector<vector<int>> &comp){
    if(vis[v]==1)
        return;
    vis[v]=1;
    comp[c].push_back(v);
    for(auto child:g[v]){
        dfs(child,c,comp);
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);

    }

    int c=0;
    vector<vector<int>> comp(1000);
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            dfs(i,c,comp);
            c++;
        }
    }

    cout<<"Number of connected components: "<<c<<endl;
    cout<<"Connected components: "<<endl;

    for(int i=0;i<c;i++){
        for(int j=0;j<comp[i].size();j++){
            cout<<comp[i][j]<<" ";
        }

        cout<<endl;
    }
}