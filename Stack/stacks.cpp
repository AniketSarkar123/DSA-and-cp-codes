#include<bits/stdc++.h>
using namespace std;

//Implementation of stack using vectors.

class Stack{
    private:
        vector<int> v;
    public:
        void push(int data){
            v.push_back(data);
        }
        bool empty(){
            if(v.size()==0)
                return true;
            else
                return false;

        }
        void pop(){
            if(!empty()){
                v.pop_back();
            }
        }
        int top(){
            return v[v.size()-1];
        }

};


int main(){
    Stack s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.push(a);
    }

    for(int i=0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }



}