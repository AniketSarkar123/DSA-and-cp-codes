#include<bits/stdc++.h>
using namespace std;

int nearly_sortedBS(vector<int> &v,int ele){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==ele)
            return mid;
        if(mid-1>s && v[mid-1]==ele)
            return mid-1;
        if(mid+1<e && v[mid+1]==ele)
            return mid+1;
        else if(v[mid]>ele)
            e=mid-1;
        else if(v[mid]<ele)
            s=mid+1;
        
    }
    return -1;
}

int main(){
    vector<int> v={5,10,30,20,40};
    cout<<nearly_sortedBS(v,80);
}