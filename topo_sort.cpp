#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool visited[100000];
stack<int> st;

int MAX(int a, int b){
    if (a>b){
        return a;
    }
    else {
        return b;
    }
}

void dfs(int node, int parent){
    if (visited[node] == false){
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++){
            dfs(adj[node][i], node);
        }
        st.push(node);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int u, v;
    int nodes = 1;
    for (int i = 0; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        nodes = MAX(nodes, u);
        nodes = MAX(nodes, v);
        visited[u] = false;
        visited[v] = false;
    }
    dfs(1, -1);
    for (int i=1; i <= nodes; i++){
        if (visited[i] == false){
            dfs (i, -1);
        }
    }
    cout << "Topological Sort: ";
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
