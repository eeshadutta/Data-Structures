#include <bits/stdc++.h>
using namespace std;

queue <int> qu;
vector <int> adj[100000];
bool visited[100000];
int depth[10000];

void bfs(int node){
    visited[node] = true;
    qu.push(node);
    depth[node] = 0;
    while(!qu.empty()){
        cout << qu.front() << " " ;
        int parent = qu.front();
        cout << "Depth:"<< depth[parent] << endl ;
        qu.pop();
        for (int i = 0; i<adj[parent].size(); i++){
            if (visited[adj[parent][i]] == false){
                qu.push(adj[parent][i]);
                visited[adj[parent][i]] = true;
                depth[adj[parent][i]] = depth[parent] + 1;
            }
        }
    }
    return;
}

int main(){
    int n;
    cout << "Enter no of edges: ";
    cin >> n;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    depth[0] = -1;
    int node;
    cout << "Node for bfs: ";
    cin >> node;
    bfs(node);
    return 0;
}