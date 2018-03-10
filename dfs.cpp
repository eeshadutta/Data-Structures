#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[100000];
bool visited[100000];

void dfs(int node, int parent){
    if (visited[node] == false){
        cout << node << " ";
        visited[node] = true;
        for (int i=0; i<adj[node].size(); i++){
            if (adj[node][i]!=parent){
                dfs(adj[node][i], node);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        visited[i]=false;
    }
    dfs(1,-1);
    cout << "\n";
    return 0;
}
