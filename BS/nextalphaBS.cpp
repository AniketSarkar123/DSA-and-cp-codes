#include<bits/stdc++.h>
using namespace std;

int nextalphaBS(vector<char> &v, char ele){
    int s=0;
    int e=v.size()-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]<=ele){
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
    vector<char> v={'a','b','c','f','h'};
    cout<<nextalphaBS(v,'f');
}