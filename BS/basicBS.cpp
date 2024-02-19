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

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    cout<<BS(v,0);
}
