#include <bits/stdc++.h>

#define pb push_back
#define nd &&
#define ou ||
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define nl '\n'

using namespace std;

vector<vector<pii>> graph;
vector<bool> visited;
vector<int> parent;
vector<int>dist;

void dijkstra(int ini) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, ini});
    dist[ini] = 0;

    while(!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(d > dist[cur]) continue; 


        for(auto [edge, weight] : graph[cur]) {
            if(dist[edge] > dist[cur] + weight) {
                dist[edge] = dist[cur] + weight;
                parent[edge] = cur;
                pq.push({dist[edge], edge});
            }
        }
    }
}

int main() {
    int number; cin >> number;
    int n, m; cin >> n >> m;

    graph.resize(n+1);
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    dist.assign(n+1, INT_MAX);

    for(int i = 0; i < m; i++) {
        int u, v, weight; cin >> u >> v >> weight;
        graph[u].pb({v, weight});
        graph[v].pb({u, weight});
    }

    dijkstra(number);

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << nl;
    }
}