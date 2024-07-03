#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
vector<int> g[N];
int subtreesum[N]={0};

void dfs(int vertex,int par=0){
    subtreesum[vertex]+=vertex;
    for(int child:g[vertex]){
        if(child==par)
            continue;
        dfs(child,vertex);
        subtreesum[vertex]+=subtreesum[child];
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

    dfs(1);
    for(int i=1;i<=m;i++){
        cout<<subtreesum[i]<<" ";
    }

    
}
