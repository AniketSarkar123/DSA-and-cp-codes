#include<bits/stdc++.h>
using namespace std;

int BSfirst_occur(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ele==v[mid]){
            res=mid;
            e=mid-1;
        }
            
        else if(ele>v[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return res;
}

int BSlast_occur(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ele==v[mid]){
            res=mid;
            s=mid+1;
        }
            
        else if(ele>v[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return res;
}


int main(){
    vector<int> v={1,5,10,10,10,10,10,10,11,22,78};
    cout<<BSfirst_occur(v,10)<<" "<<BSlast_occur(v,10);
}