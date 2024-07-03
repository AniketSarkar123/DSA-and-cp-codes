#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<vector<pair<int,int>>> &g,vector<int> &vis,stack<int> &s){
    if(vis[v]==1)
        return;
    vis[v]=1;
   
   
    for(auto child:g[v]){
        
            dfs(child.first,g,vis,s);
    }

     s.push(v);

}

int main(){
    int n,m;
    cin>>n>>m;
    int src;
    cin>>src;
    vector<vector<pair<int,int>>> g(n);
    vector<int> dist(n,INT_MAX);
    vector<int> vis(n,0);
    stack<int> s;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
       g[x].push_back({y,wt});
    }

    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i,g,vis,s);
           
        
    }

    dist[src]=0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        for(auto child:g[t]){
            if(dist[t]+child.second<dist[child.first])
                dist[child.first]=dist[t]+child.second;

        }
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";


}
