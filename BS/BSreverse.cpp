#include<bits/stdc++.h>
using namespace std;

int BSreverse(vector<int> &v, int ele){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(ele==v[mid])
            return mid;
        else if(ele>v[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    return -1;
}

int main(){
    vector<int> v={10,9,8,7,6,5,4,3,2,1};
    cout<<BSreverse(v,2);
}