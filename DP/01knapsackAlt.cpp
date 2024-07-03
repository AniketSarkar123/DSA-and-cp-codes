#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int knapsack(vector<int> &wt,vector<int> &val,int w,int n){
    if(n==0 || w==0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n-1]<=w)
        return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    else if(wt[n-1]>w)
        return dp[n][w]=knapsack(wt,val,w,n-1);
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,amount;
    cin>>n>>amount;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<knapsack(wt,val,amount,n);
    
}