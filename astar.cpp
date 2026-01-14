#include <bits/stdc++.h>
using namespace std;


#define f first
#define s second
#define pb push_back
#define nd &&
#define ou ||
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define nl '\n'

vector<vector<int>> labirinto;
vector<vector<int>>dist;
vector<vector<pii>> parent;

int manhattan(pii a, pii b) {
    return abs(b.f - a.f) + abs(b.s - a.s);
}

void astar(pii ini, pii fim, int n, int m) {
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    dist[ini.f][ini.s] = 0;
    pq.push({manhattan(ini, fim), ini});

    vector<pii> moves = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(cur == fim) return; 
        if(dist[cur.f][cur.s] == INT_MAX) continue;

        for(auto [dx,dy] : moves) {
            int nx = cur.f + dx, ny = cur.s + dy;
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(labirinto[nx][ny] == 1) continue; 

            if(dist[nx][ny] > dist[cur.f][cur.s] + 1) {
                dist[nx][ny] = dist[cur.f][cur.s] + 1;
                parent[nx][ny] = cur;
                int h = manhattan({nx,ny}, fim);
                pq.push({dist[nx][ny] + h, {nx,ny}});

            }
        }
    }
}

void solve() {
    int beginx, beginy; cin >> beginx >> beginy;
    int n, m; cin >> n >> m;

    labirinto.resize(n, vector<int>(m));
    dist.assign(n, vector<int>(m, INT_MAX));
    parent.assign(n, vector<pii>(m, {-1,-1}));

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> labirinto[i][j]; 
    }

    astar({beginx, beginy}, {n-1, m-1}, n, m);

    if(dist[n-1][m-1] == INT_MAX) cout << "No path" << nl;
    else cout << "D: " << dist[n-1][m-1] << nl;

    vector<pii> path;
    pii cur = {n-1, m-1};
    while(cur.f != -1 && cur.s != -1) {
        path.push_back(cur);
        cur = parent[cur.f][cur.s];
    }
    reverse(path.begin(), path.end());


    for(auto [x,y] : path) {
        cout << "(" << x << "," << y << ") ";
    }
    cout << nl;

}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
