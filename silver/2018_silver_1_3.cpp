#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin.tie(NULL);
    int N;
    int Q;
    cin >> N >> Q;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        p--;
        q--;
        adj[p].push_back(make_pair(q, r));
        adj[q].push_back(make_pair(p, r));
    }
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        v--;
        int ans = 0;
        queue<int> q;
        vector<bool> visited(N, false);
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            int video = q.front();
            q.pop();
            for (const pair<int, int>& edge : adj[video]) {
                if (!visited[edge.first] && edge.second >= k) {
                    visited[edge.first] = true;
                    ans++;
                    q.push(edge.first);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}