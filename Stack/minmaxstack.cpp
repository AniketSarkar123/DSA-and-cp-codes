#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,3,4,9,8,7,8,3,4};
    stack<int> s,s1;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        s1.push(arr[i]);
    }
    
    int min=s.top();
    for(int i=0;i<n;i++){
        s.pop();
        int next=s.top();
        if(next<min){
            min=next;
        }

    }
    int max=s1.top();
    while(!s1.empty()){
        s1.pop();
        if(s1.top()>max){
            max=s1.top();
        }
    }

    cout<<"Minimum"<<':'<<min<<endl;
    cout<<"Maximum"<<':'<<max<<endl;
}
