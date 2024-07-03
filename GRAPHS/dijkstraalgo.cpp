#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;

vector<pair<int,int>> g[N];
vector<int> dist(N,INT_MAX);
//int vis[N]={0};

void dijkstra(int src){
    set<pair<int,int>> st; //{p.fr,p.sc} here p.fr contains the distance and p.sc the value of the node..
    st.insert({0,src});
    dist[src]=0;
    while(st.size()>0){
        auto node=*st.begin();
        int d=node.first;
        int v=node.second;
        st.erase(st.begin());
       
        for(auto child:g[v]){
            int c_node=child.first;
            int c_d=child.second;
            if(dist[v]+c_d<dist[c_node]){
                dist[c_node]=dist[v]+c_d;
                st.insert({dist[c_node],c_node});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt}); //{p.fr,p,sc} here p.fr contains the name of the destination node and wt is the distance..
    }


    dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}