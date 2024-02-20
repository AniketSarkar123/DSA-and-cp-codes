#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ele==v[mid])
            return mid;
        else if(ele>v[mid])
            s=mid+1;
        else
            e=mid-1;
    }
    return -1;
}


int floorBS(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==ele)
            return mid;
        else if(v[mid]<ele){
            res=mid;
            s=mid+1;
        }
        else
            e=mid-1;

        
    }
    return res;
}

int ceilBS(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==ele)
            return mid;
        else if(v[mid]<ele){
            s=mid+1;
        }
        else{
            res=mid;
            e=mid-1;
        }

        
    }
    return res;
}

int main(){
    vector<int> v={1,2,3,7,9,10,14,15,18};
    int key=12;
    if(BS(v,key)!=-1)
        cout<<BS(v,key);
    if(abs(v[floorBS(v,key)]-key)>abs(v[ceilBS(v,key)]-key))
        cout<<ceilBS(v,key);
    else   
        cout<<floorBS(v,key);
}
