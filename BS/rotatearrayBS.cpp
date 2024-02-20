#include<bits/stdc++.h>
using namespace std;

int rotate_timesBS(vector<int> &v,int n){
    int s=0;
    int e=n-1;
    while(s<=e){
       int mid=s+(e-s)/2;
       int prev=(mid+n-1)%n;
       int next=(mid+1)%n;
       if(v[s]<v[e])
            return s;
       if(v[mid]<=v[next] && v[mid]<=v[prev])
            return mid;
       else if(v[s]<=v[mid])
            s=mid+1;
       else if(v[mid]<=v[e])
            e=mid-1;
      


    }
}

int main(){
    vector<int> v={11,12,15,18,2,5,6,8};
    cout<<rotate_timesBS(v,8);
}