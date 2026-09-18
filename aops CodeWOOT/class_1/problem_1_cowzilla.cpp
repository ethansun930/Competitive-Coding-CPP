#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<double> r(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        r[i] = log10(x);
    }
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<double> d(N, INT_MAX);
    d[0] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        pair<double, int> v = pq.top();
        pq.pop();
        if (v.first > d[v.second]) {
            continue;
        }
        if (v.second == N - 1) {
            break;
        }
        for (pair<int, int> e : adj[v.second]) {
            if (v.first >= e.second) {
                continue;
            }
            int neighbor = e.first;
            if (v.first + r[neighbor] >= d[neighbor]) {
                continue;
            }
            d[neighbor] = v.first + r[neighbor];
            pq.push({d[neighbor], neighbor});
        }
    }
    if (d[N - 1] == INT_MAX) {
        cout << -1 << '\n';
        return;
    }
    cout << floor(d[N - 1]) + 1 << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}