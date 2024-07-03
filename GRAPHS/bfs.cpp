#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
vector<int> g[N];
vector<bool> vis(N);
vector<int> level(N);

void bfs(int src){
    queue<int> q;
    q.push(src);
    cout<<src<<" ";
    vis[src]=1;
    while(!q.empty()){
        int frt=q.front();
        q.pop();
        if(!vis[frt]){
            cout<<frt<<" ";
            vis[frt]=1;
        }
        for(auto child:g[frt]){
            if(!vis[child]){
                q.push(child);
                

            }
        }

        

    }

}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);
}