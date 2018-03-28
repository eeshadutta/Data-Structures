#include <bits/stdc++.h>
using namespace std;

vector <int> g[100005];
vector <int> gr[100005];
stack <int> st;
bool visited[100005];

void dfs_topo(int node){
    if (visited[node] == false){
        visited[node] = true;
        for (int i=0; i<g[node].size(); i++){
            dfs_topo(g[node][i]);
        }
        st.push(node);
    }
    return;
}

void dfs_reverse(int node){
    if (visited[node] == false){
        visited[node] = true;
        cout << node << " ";
        for (int i=0; i<gr[node].size(); i++){
            dfs_reverse(gr[node][i]);
        }
    }
    return;
}

int main(){
    int e, v;
    cout << "Edges and Vertices: ";
    cin >> e >> v;
    for (int i=1; i<=e; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for (int i=1; i<=v; i++){
        visited[i] = false;
    }
    dfs_topo(1);
    for (int i=1; i <= v; i++){
        if (visited[i] == false){
            dfs_topo(i);
        }
    }

    for (int i=1; i<=v; i++){
        visited[i] = false;
    }

    while(!st.empty()){
        int node = st.top();
        if (visited[node] == false){
            dfs_reverse(node);
            cout << endl;
        }
        st.pop();
    }
    return 0;
}