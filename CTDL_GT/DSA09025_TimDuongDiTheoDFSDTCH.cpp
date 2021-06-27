#include <bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define base 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector <int> vi;
typedef vector <string> vs;

void solve(){
    int n, k, visited[1005]={0}, s, t, truoc[1005]={0};
    cin >> n >> k >> s >> t;
    vector <int> g[1005];
    for (int i=0; i<k; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    stack <int> st;
    visited[s]=1;
    st.push(s);
    while (!st.empty()){
        int x=st.top();
        st.pop();
        for (auto j:g[x]){
            if (!visited[j]){
                visited[j]=1;
                truoc[j]=x;
                st.push(x);
                st.push(j);
                break;
            } 
        }
    }
    if (visited[t]==1){
        stack <int> s2;
        s2.push(t);
        while (truoc[t]!=s){
            s2.push(truoc[t]);
            t=truoc[t];
        }
        s2.push(s);
        while(!s2.empty()){
            cout << s2.top() << " ";
            s2.pop();
        }
    }
    else cout << -1;
    cout << endl;
}

int main(){
    faster();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}