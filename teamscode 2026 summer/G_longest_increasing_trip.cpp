#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void DFS(vector<vector<pair<int, int>>>& adj, int node, int& ans, int& amount,
         int prev, int l) {
    if (l > ans) {
        ans = l;
        amount = 1;
    } else if (l == ans) {
        amount++;
    }
    for (int i = adj[node].size() - 1; i >= 0; i--) {
        int neighbor = adj[node][i].second;
        int weight = adj[node][i].first;
        if (weight <= prev) {
            break;
        }
        DFS(adj, neighbor, ans, amount, weight, l + 1);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int ans = 0;
    int amount = 0;
    for (int i = 0; i < n; i++) {
        DFS(adj, i, ans, amount, -1, 0);
    }
    cout << ans << ' ' << amount << '\n';
    return 0;
}