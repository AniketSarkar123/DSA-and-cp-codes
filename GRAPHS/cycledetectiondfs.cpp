#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> g[N];
int vis[N]={0};

bool dfs(int v,int par){
    vis[v]=1;
   
    bool ifloop=0;
    for(auto child:g[v]){
        if((vis[child]==1) && child==par)
            continue;
        if(vis[child])
            return true;
        
        
        ifloop|=dfs(child,v);
    }

    return ifloop;
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

    int f=false;
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            f=dfs(i,0);
            break;
        }
    }

    cout<<f<<endl;




}

