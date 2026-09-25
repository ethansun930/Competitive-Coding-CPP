#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int S, N, X;
    cin >> S >> N >> X;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < S; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        adj[a].push_back({d, b});
    }
    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> visited(N, INT_MIN);
    visited[0] = 1000000;
    queue<pair<int, int>> q;
    q.push({1000000, 0});
    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        if (node.first >= X) {
            cout << "YES" << '\n';
            return;
        }
        if (visited[node.second] > node.first) {
            continue;
        }
        for (pair<int, int> e : adj[node.second]) {
            if (node.first - e.first < 0) {
                break;
            }
            if (visited[e.second] >= (node.first - e.first)) {
                continue;
            }
            visited[e.second] = node.first - e.first;
            q.push({node.first - e.first, e.second});
        }
    }
    cout << "NO" << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}