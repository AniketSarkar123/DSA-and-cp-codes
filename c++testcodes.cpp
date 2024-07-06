#include <bits/stdc++.h>

#define pb push_back
#define fr first
#define sc second

#define sz(x) x.size()
#define rep(n) for(ll i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define acm(v) accumulate(all(v),0)
#define op(v) cout<<v<<'\n'
#define op2(v) cout<<v<<" "

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int mod = 1e9+7;

ll gcd(ll m,ll n){
    if(m%n==0) return n;
    else return gcd(n,m%n);
}

void fastIO(){
    ios::sync_with_stdio(0);
    cin.tie(0);      //turn off for debug,interactive prob
}

ll digsum(string s){
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0');
    }

    return ans;
}

void f(int n,map<int,int> &m){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            m[i]++;
            n/=i;
        }
    }

    if(n>1)
        m[n]++;
}

void f2(int n,map<int,int> &m){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            m[i]--;
            n/=i;
        }
    }

    if(n>1)
        m[n]--;
}

bool isprime(int n){
    if(n==2)
        return true;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }

    return true;
}

string dectobase9(ll k){
    string res="";
    if(k==0)
        return "0";
    while(k!=0){
        int rem=k%9;
        res+=to_string(rem);
        k/=9;
    }

    reverse(all(res));
    return res;
}

ll modcomp(ll x,ll e){
    return (x-(e%x))%x;
}

int len(int x){
    return (log10(x)+1);
}

ll trail(ll x){
    ll c=10;
    ll res=0;
    while(x%c==0){
        c*=10;
        res++;
    }

    return res;
}

int check=1;

ll BinaryExpo(ll a,ll b,ll M){
    ll ans=1;
    if(a==0)
        return 0;
    while(b){
        if(b&1){
            ans=(ans*a)%M;
        }

        a=(a*a)%M;
        b>>=1;
    }

    return ans;
}

int sv=0;
int ev=0;
int M=1000000007;

void dijkstra(int src, int n, vector<int> &dist, vector<int> &parent, vector<vector<pair<int,int>>> &g){
    set<pair<int,int>> st; // {distance, node}
    st.insert({0, src});
    dist[src] = 0;
    
    while(!st.empty()){
        auto node = *st.begin();
        int d = node.first;
        int v = node.second;
        st.erase(st.begin());
        
        for(auto child : g[v]){
            int c_node = child.first;
            int c_d = child.second;
            
            if(dist[v] + c_d < dist[c_node]){
                st.erase({dist[c_node], c_node});
                dist[c_node] = dist[v] + c_d;
                parent[c_node] = v;
                st.insert({dist[c_node], c_node});
            }
        }
    }
}

vector<int> reconstructPath(int src, int dest, vector<int> &parent) {
    vector<int> path;
    for (int v = dest; v != src; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    dijkstra(1, n, dist, parent, g);

    vector<int> path = reconstructPath(1, n, parent);
    if(dist[n] == INT_MAX) {
       op(-1);
       return;
    } else {
       

        vector<int> edge_weights;
        for(int i = 1; i < path.size(); ++i) {
            int u = path[i-1];
            int v = path[i];
            for(auto &p : g[u]) {
                if(p.first == v) {
                    edge_weights.push_back(p.second);
                    break;
                }
            }
        }

        int maxi=*max_element(all(edge_weights));
        int ind=0;
        for(int i=0;i<edge_weights.size();i++){
          if(edge_weights[i]==maxi){
            ind=i;
            break;
          }
        }

        edge_weights[ind]/=2;
        op(accumulate(all(edge_weights),0ll));

       
    }
}

int main(){
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}
