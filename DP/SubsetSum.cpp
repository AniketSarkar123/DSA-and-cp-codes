#include<bits/stdc++.h>
using namespace std;
bool dp[1000][1000];

bool func(vector<int> &arr,int sum,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
                dp[i][j]=false;
            else if(j==0)
                dp[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<func(arr,sum,n);
}