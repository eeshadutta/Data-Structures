#include <bits/stdc++.h>
using namespace std;

vector <pair<int, pair<int, int> > > edges;
int parent[100005];
int size[100005];
int total_weight = 0;

int find(int x){
    if (parent[x] == x) return x;
    return find(parent[x]);
}

void merge(int a, int b){
    int aparent = find(a);
    int bparent = find(b);
    if (aparent == bparent) return;
    else if (size[a] <= size[b]){
        parent[aparent] = bparent;
        size[bparent] += size[aparent];
    }
    else {
        parent[bparent] = aparent;
        size[aparent] += size[bparent];
    }
    return;
}

int main(){
    int v, e;
    cin >> v >> e;
    for (int i=1; i<=e; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, {u, v}});
        parent[u] = u;
        parent[v] = v;
        size[u] = 1;
        size[v] = 1; 
    }    
    sort(edges.begin(), edges.end());
    cout << "MST:\n"; 
    for (auto e: edges){
        if (find(e.second.first) != find(e.second.second)){
            total_weight += e.first;
            cout << e.second.first << " " << e.second.second << "\n";
            merge(e.second.first, e.second.second);            
        }
    }
    cout << "MST Weight: " << total_weight << "\n";
}