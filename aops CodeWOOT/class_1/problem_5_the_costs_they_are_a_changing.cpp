#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    long long a, b, c, d;
};
void solve() {
    long long N, M;
    cin >> N >> M;
    vector<Edge> e(M);
    vector<vector<int>> rev_adj(N);
    for (long long i = 0; i < M; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c >> e[i].d;
        e[i].a--;
        e[i].b--;
        rev_adj[e[i].b].push_back(e[i].a);
    }
    vector<bool> reachable(N, false);
    queue<int> q;
    q.push(N - 1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (reachable[node]) {
            continue;
        }
        reachable[node] = true;
        for (const int& neighbor : rev_adj[node]) {
            if (reachable[neighbor]) {
                continue;
            }
            q.push(neighbor);
        }
    }
    if (!reachable[0]) {
        cout << "UNREACHABLE" << '\n';
        return;
    }
    vector<long long> d(2 * N, LLONG_MAX);
    d[0] = 0;
    for (long long t = 0; t < (2 * N - 1); t++) {
        for (long long i = 0; i < M; i++) {
            if (e[i].d == 0) {
                if (d[e[i].a + N] != LLONG_MAX) {
                    d[e[i].b] = min(d[e[i].b], d[e[i].a + N] + e[i].c);
                }
                if (d[e[i].a] != LLONG_MAX) {
                    d[e[i].b + N] = min(d[e[i].b + N], d[e[i].a] + e[i].c);
                }
            } else {
                if (d[e[i].a + N] != LLONG_MAX) {
                    d[e[i].b] = min(d[e[i].b], d[e[i].a + N] - e[i].c);
                }
                if (d[e[i].a] != LLONG_MAX) {
                    d[e[i].b + N] = min(d[e[i].b + N], d[e[i].a] + e[i].c);
                }
            }
        }
    }
    for (long long i = 0; i < M; i++) {
        if (e[i].d == 0) {
            if (d[e[i].a + N] != LLONG_MAX) {
                if (d[e[i].a + N] + e[i].c < d[e[i].b] && reachable[e[i].b]) {
                    cout << "UNBOUNDED" << '\n';
                    return;
                }
            }
            if (d[e[i].a] != LLONG_MAX) {
                if (d[e[i].a] + e[i].c < d[e[i].b + N] && reachable[e[i].b]) {
                    cout << "UNBOUNDED" << '\n';
                    return;
                }
            }
        } else {
            if (d[e[i].a + N] != LLONG_MAX) {
                if (d[e[i].a + N] - e[i].c < d[e[i].b] && reachable[e[i].b]) {
                    cout << "UNBOUNDED" << '\n';
                    return;
                }
            }
            if (d[e[i].a] != LLONG_MAX) {
                if (d[e[i].a] + e[i].c < d[e[i].b + N] && reachable[e[i].b]) {
                    cout << "UNBOUNDED" << '\n';
                    return;
                }
            }
        }
    }
    cout << min(d[N - 1], d[2 * N - 1]) << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}