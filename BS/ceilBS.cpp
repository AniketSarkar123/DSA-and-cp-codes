#include<bits/stdc++.h>
using namespace std;

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
    vector<int> v={1,2,3,8,9,10,11,18};
    cout<<ceilBS(v,5);
}