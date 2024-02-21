#include<bits/stdc++.h>
using namespace std;

/*QUESTION:
You are given an array. Task is to print the next largest number of an element of the array.
The result array is as follows:
INPUT: {4,5,2,25,7,8}
OUTPUT: {5,25,25,-1,8,-1}*/

vector<int> NGR(vector<int> v){
    vector<int> ngr(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[i]>v[st.top()]){
                ngr[st.top()]=i;
                st.pop();


        }
        st.push(i);
        
        }
        while(!st.empty()){
            ngr[st.top()]=-1;
            st.pop();

    }
    return ngr;
}

vector<int> NSR(vector<int> v){
    vector<int> nsr(v.size());
    stack<int> st;
    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[i]<v[st.top()]){
                nsr[st.top()]=i;
                st.pop();


        }
        st.push(i);
        
        }
        while(!st.empty()){
            nsr[st.top()]=-1;
            st.pop();

    }
    return nsr;
}

vector<int> NGL(vector<int> v){
    vector<int> ngl(v.size());
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--){
        while(!st.empty() && v[i]>v[st.top()]){
                ngl[st.top()]=i;
                st.pop();


        }
        st.push(i);
        
        }
        while(!st.empty()){
            ngl[st.top()]=-1;
            st.pop();

    }
    return ngl;
}

vector<int> NSL(vector<int> v){
    vector<int> nsl(v.size());
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--){
        while(!st.empty() && v[i]<v[st.top()]){
                nsl[st.top()]=i;
                st.pop();


        }
        st.push(i);
        
        }
        while(!st.empty()){
            nsl[st.top()]=-1;
            st.pop();

    }
    return nsl;
}





int main(){
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> ngr= NGR(v);
    vector<int> valg;
    vector<int> nsr=NSR(v);
    vector<int> vals;
    vector<int> ngl=NGL(v);
    vector<int> valg1;
    vector<int> nsl=NSL(v);
    vector<int> vals1;


    for(i=0;i<n;i++){
        int x=(ngr[i]==-1 ? -1 :v[ngr[i]]);
        valg.push_back(x);

    }
    cout<<"NGR:"<<endl;
    for(i=0;i<n;i++){
        cout<<ngr[i]<<":"<<valg[i]<<endl;
    }
    cout<<endl;
    for(i=0;i<n;i++){
        int x=(nsr[i]==-1 ? -1 :v[nsr[i]]);
        vals.push_back(x);

    }
    cout<<"NSR"<<endl;
    for(i=0;i<n;i++){
        cout<<nsr[i]<<":"<<vals[i]<<endl;
    }
    cout<<endl;
    for(i=0;i<n;i++){
        int x=(ngl[i]==-1 ? -1 :v[ngl[i]]);
        valg1.push_back(x);

    }
    cout<<"NGL"<<endl;
    for(i=0;i<n;i++){
        cout<<ngl[i]<<":"<<valg1[i]<<endl;
    }
    cout<<endl;
    for(i=0;i<n;i++){
        int x=(nsl[i]==-1 ? -1 :v[nsl[i]]);
        vals1.push_back(x);

    }
    cout<<"NSL"<<endl;
    for(i=0;i<n;i++){
        cout<<nsl[i]<<":"<<vals1[i]<<endl;
    }


}


