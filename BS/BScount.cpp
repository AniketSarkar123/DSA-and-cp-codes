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
    vector<int> v={1,5,6,10,10,10,10,10,11,17,88,99};
    cout<<BSlast_occur(v,10)-BSfirst_occur(v,10)+1;
}