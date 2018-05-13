#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
vector <int> weights[100005];
int dist[100005];
priority_queue <pair<int, int> > minheap;

int main(){
    int v, e;
    cin >> v >> e;
    for (int i=1; i<=e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a].push_back(w);
        weights[b].push_back(w);
    }
    int source, dest;
    cin >> source >> dest;
    dist[source] = 0;
    minheap.push(make_pair(-dist[source], source));
    while(!minheap.empty()){
        pair <int, int> temp;
        temp = minheap.top();
        int node = temp.second;
        int d = temp.first;
        if (d > dist[node]){
            continue;
        }
        for (int i=0; i<adj[node].size(); i++){
            if (dist[node] + weights[node][i] <= dist[adj[node][i]]){
                dist[adj[node][i]] = dist[node] + weights[node][i];
                minheap.push(make_pair(-dist[adj[node][i]], adj[node][i]));
            }
        }
        minheap.pop();
    }
    for (int i=1; i<=v; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}