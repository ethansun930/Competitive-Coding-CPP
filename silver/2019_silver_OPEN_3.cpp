#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void DFS(vector<pair<int, int>>& coordinates, vector<vector<int>>& adj,
         vector<bool>& visited, int& x_max, int& x_min, int& y_max, int& y_min,
         int i) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    x_max = max(x_max, coordinates[i].first);
    x_min = min(x_min, coordinates[i].first);
    y_max = max(y_max, coordinates[i].second);
    y_min = min(y_min, coordinates[i].second);
    for (int j : adj[i]) {
        DFS(coordinates, adj, visited, x_max, x_min, y_max, y_min, j);
    }
}
int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> coordinates(N);
    for (int i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 2147483647;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int x_max = 0;
            int x_min = 100000000;
            int y_max = 0;
            int y_min = 100000000;
            DFS(coordinates, adj, visited, x_max, x_min, y_max, y_min, i);
            ans = min(ans, 2 * (x_max - x_min + y_max - y_min));
        }
    }
    cout << ans << '\n';
    return 0;
}
