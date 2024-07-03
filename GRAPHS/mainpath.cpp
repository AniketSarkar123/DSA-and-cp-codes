#include<bits/stdc++.h>
using namespace std;
#define ll long long


void minpath(ll node,vector<vector<pair<ll,ll>>> &g,vector<vector<ll>> &dist,vector<ll> &vis){
        set<pair<ll,ll>> s;
        dist[node][node]=0;
        s.insert({0,node});
        while(s.size()>0){
           auto p=*s.begin();
            s.erase(s.begin());
            ll t=p.second;
            
            for(auto child:g[t]){
                ll cnode=child.first;
                ll d=child.second;
                if(dist[node][t]+d<dist[node][cnode]){
                    dist[node][cnode]=dist[node][t]+d;
                    s.insert({dist[node][cnode],cnode});
                }
            }
        }
    }