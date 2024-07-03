#include<bits/stdc++.h>
using namespace std;

int a[100005], seg[4*100005];
void build(int ind,int l,int h){
    if(l==h){
        seg[ind]=a[l];
        return;
    }
    int mid=l+(h-l)/2;
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,h);
    seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);

}

int query(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r)
        return seg[ind];
    if(low>r || high<l)
      return 0;
    int mid=low+(high-low)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return (left+right);


}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }


}