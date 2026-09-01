#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void DFS(vector<vector<pair<long long, long long>>>& adj, vector<bool>& visited,
         vector<long long>& sign, vector<long long>& C, vector<long long>& comp,
         bool& force, bool& imp, long long& force_val, long long node,
         long long s, long long c) {
    if (imp) {
        return;
    }
    visited[node] = true;
    sign[node] = s;
    C[node] = c;
    comp.push_back(node);
    for (const pair<long long, long long>& edge : adj[node]) {
        long long neighbor = edge.first;
        long long weight = edge.second;
        if (!visited[neighbor]) {
            DFS(adj, visited, sign, C, comp, force, imp, force_val, neighbor,
                -s, weight - c);
        } else {
            if (sign[neighbor] == -s) {
                if (C[neighbor] != weight - c) {
                    imp = true;
                    return;
                }
            } else {
                if ((weight - c - C[neighbor]) % 2 != 0) {
                    imp = true;
                    return;
                } else {
                    if (force &&
                        (force_val != (weight - c - C[neighbor]) / (2 * s))) {
                        imp = true;
                        return;
                    }
                    force = true;
                    force_val = (weight - c - C[neighbor]) / (2 * s);
                    // remember to add 2 * s because the sign matters
                }
            }
        }
    }
}

void solve() {
    long long N, M;
    cin >> N >> M;
    vector<long long> l(N);
    for (long long i = 0; i < N; i++) {
        cin >> l[i];
    }
    vector<long long> r(N);
    for (long long i = 0; i < N; i++) {
        cin >> r[i];
    }
    vector<vector<pair<long long, long long>>> adj(N);
    for (long long i = 0; i < M; i++) {
        long long x, y;
        long long z;
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    vector<bool> visited(N, false);
    vector<long long> sign(N, 0);
    vector<long long> C(N, 0);
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        vector<long long> comp;
        bool force = false;
        bool imp = false;
        long long force_val = 0;
        DFS(adj, visited, sign, C, comp, force, imp, force_val, i, 1, 0);
        if (imp) {
            cout << -1 << '\n';
            return;
        }
        if (force) {
            for (const long long& j : comp) {
                if ((l[j] <= (sign[j] * force_val + C[j])) &&
                    (r[j] >= (sign[j] * force_val + C[j]))) {
                    ans++;
                }
            }
        } else {
            vector<pair<long long, long long>> sweep;
            for (const long long& j : comp) {
                if (sign[j] == 1) {
                    sweep.push_back({l[j] - C[j], 1});
                    sweep.push_back({r[j] - C[j] + 1, -1});
                } else {
                    sweep.push_back({C[j] - r[j], 1});
                    sweep.push_back({C[j] - l[j] + 1, -1});
                }
            }
            sort(sweep.begin(), sweep.end());
            long long curr = 0;
            long long maximum = 0;
            long long j = 0;
            while (j < sweep.size()) {
                long long curr_t = sweep[j].first;
                while (j < sweep.size() && sweep[j].first == curr_t) {
                    curr += sweep[j].second;
                    j++;
                }
                maximum = max(maximum, curr);
            }
            ans += maximum;
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}