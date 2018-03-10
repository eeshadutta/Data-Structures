#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> adj[1000];
    int n;
    cin>>n;
    int u, v;
    for (int i=0; i<n; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        cout << "Adjacency list of " << i << ": ";
        for (int j=0; j<adj[i].size(); j++){
            cout << adj[i][j]  << " ";
        }
        cout << endl;
    }
    return 0;
}