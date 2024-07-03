#include<bits/stdc++.h>
using namespace std;

int lis(int i,vector<int> &v,int v1[]){
        if(v1[i]!=-1) return v1[i];
        int ans=1;
        for(int j=0;j<i;j++){
            if(v[i]>v[j])
                ans=max(ans,lis(j,v,v1)+1);
        }
        return v1[i]=ans;
    }

int main(){
    int n;
    cin>>n;
    int dp[n];
    memset(dp,-1,sizeof(dp));
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,lis(i,v,dp));
    }

    cout<<ans<<endl;
}