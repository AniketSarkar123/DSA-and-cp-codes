#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &arr,int sum,int n,vector<vector<int>> &dp){
    if(n==0 && sum>0)
        return 0;
    if(n==1){
        if(sum==0){
            if(arr[0]==0)
                return 2;
            else
                return 1;
        }
        else{
            if(arr[0]==sum)
                return 1;
            else
                return 0;
        }

    }

    if(n==0 && sum==0)
        return 1;
        
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(arr[n-1]<=sum)
        return dp[n][sum]=func(arr,sum-arr[n-1],n-1,dp)+func(arr,sum,n-1,dp);
    return dp[n][sum]=func(arr,sum,n-1,dp);
}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    cout<<func(arr,sum,n,dp);
}