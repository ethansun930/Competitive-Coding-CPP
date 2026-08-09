#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Flight {
    int r, d, s;
    bool operator<(const Flight& other) const { return r < other.r; }
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Flight>> adj(N);
    for (int i = 0; i < M; i++) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        c--;
        d--;
        adj[c].push_back({r, d, s});
    }
    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> layover(N);
    for (int i = 0; i < N; i++) {
        cin >> layover[i];
    }
    layover[0] = 0;
    vector<int> ans(N, 2e9);
    ans[0] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> node = q.top();
        // cout << node.first << ' ' << node.second << '\n';
        q.pop();
        if (node.second > ans[node.first]) {
            continue;
        }
        while (!adj[node.first].empty() &&
               adj[node.first].back().r >=
                   (node.second + layover[node.first])) {
            if (adj[node.first].back().s < ans[adj[node.first].back().d]) {
                ans[adj[node.first].back().d] = adj[node.first].back().s;
                q.push({adj[node.first].back().d, adj[node.first].back().s});
            }
            adj[node.first].pop_back();
        }
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] != 2e9) {
            cout << ans[i] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
