#include<bits/stdc++.h>
using namespace std;

/* Question: Suppose you are at the base of the stairs, and you can climb the stairs at a max of k steps given
as an input. Compute the number of ways you can reach the last stair.*/

int ladder_topdown(int n,int k,int dp[]){
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ways=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0)
            ways+=ladder_topdown(n-i,k,dp);
    }
    return dp[n]=ways;
}


int ladder_bottomup(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0)
                dp[i]+=dp[i-j];
        }
    }
    return dp[n];



}

int ladder_opti(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){

            dp[i]=2*dp[i-1];
    }
        
    for(int i=k+1;i<n+1;i++){
        dp[i]=2*dp[i-1]-dp[i-k];
    }
    return dp[n];
}





int main(){
    int n,k;
    cin>>n>>k;
    int dp[100]={0};
    cout<<"Steps: "<<ladder_opti(n,k);

}