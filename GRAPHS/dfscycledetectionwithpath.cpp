#include<bits/stdc++.h>
using namespace std;

 bool dfsiscyclic(int v,vector<vector<int>> &g,vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        vis[v]=1;
        pathvis[v]=1;
        for(auto child:g[v]){
            if(!vis[child]){
                if(dfsiscyclic(child,g,vis,pathvis,check))
                    return true;
            }

            if(pathvis[child])
                return true;
        }

        check[v]=1;
        pathvis[v]=0;
        return false;


    }