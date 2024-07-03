#include<bits/stdc++.h>
using namespace std;

vector<int> bfstopo(vector<vector<int>> &g,vector<int> &ind){
    int n=g.size();
    vector<int> topo;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int t=q.front();
        q.pop();
        topo.push_back(t);
        for(auto child:g[t]){
            ind[child]--;
            if(ind[child]==0)
                q.push(child);
        }
    }

    return topo;

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }

    vector<int> ind(n,0);
    for(int i=0;i<n;i++){
        for(auto child:g[i])
            ind[child]++;
    }

    vector<int> topo=bfstopo(g,ind);
    for(int i=0;i<n;i++)
        cout<<topo[i]<<" ";
    
}