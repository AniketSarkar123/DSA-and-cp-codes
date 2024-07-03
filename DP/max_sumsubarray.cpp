#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n){
    int dp[100]={0};
    dp[0]=arr[0]>0?arr[0]:0;
    int max_new=dp[0];
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
            dp[i]=0;
        max_new=max(dp[i],max_new);
    }
    return max_new;


}

int max_opti(int arr[],int n){
    int max_new=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        max_new+=arr[i];
        if(max_new<0)
            max_new=0;
        maxi=max(maxi,max_new);
        
    }
    return maxi;
}

int main(){
    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<max_opti(arr,n);
}