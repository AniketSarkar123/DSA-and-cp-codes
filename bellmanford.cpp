#include<bits/stdc++.h>
using namespace std;

//this algo is similar to dijkstra but we cannot user dijkstra here as the edges can be negative in a loop in that case dijkstra will give tle in 
//that case we use Bekllman Ford algorithm 
//iterating (m-1) times where m is the number of edges makes sure we fill the entire array, if it is not the case than shortest path is not possible.
void bellman_ford(vector<vector<int>> &connect,vector<int> &dist){
    int m=connect.size();
    for(int i=0;i<m-1;i++){
        for(auto it:connect){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]+wt<dist[v] && dist[u]!=INT_MAX){
                dist[v]=dist[u]+wt;
            }
        }
    }

    for(auto it:connect){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]+wt<dist[v] && dist[u]!=INT_MAX){
                return;
            }
        }




}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> connect(m);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        connect[i]={u,v,wt};
    }

    vector<int> dist(n,INT_MAX);
    dist[0]=0;

    bellman_ford(connect,dist);
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
    
        

    


}