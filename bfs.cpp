#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl '\n'

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;

bool bfs(int ini, int fim) {
    queue<int> q;
    q.push(ini);
    visited[ini] = true;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == fim) return true;

        for(int x : graph[cur]) {
            if(!visited[x]) {
                visited[x] = true;
                parent[x] = cur;
                q.push(x);
            }
        }
    }
    return false;
}

int main() {
    int x, y; cin >> x >> y; 
    int n, m; cin >> n >> m;  

    graph.resize(n+1);
    visited.assign(n+1, false);
    parent.assign(n+1, -1);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    bool found = bfs(x,y);

    if(!found) {
        cout << "There is no path between those vertices" << nl;
    } else {
        int dist = 0;
        int cur = y;
        while(cur != x) {
            cur = parent[cur];
            dist++;
        }
        cout << dist << nl;
    }
}