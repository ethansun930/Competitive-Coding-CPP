#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long min_dist(vector<long long>& from, vector<long long>& to) {
    long long ans = LLONG_MAX;
    for (long long x : from) {
        auto it = lower_bound(to.begin(), to.end(), x);
        if (it != to.end()) {
            ans = min(ans, ((*it - x) * (*it - x)));
        }
        if (it != to.begin()) {
            it--;
            ans = min(ans, ((*it - x) * (*it - x)));
        }
    }
    return ans;
}
void dfs(vector<vector<long long>>& adj, vector<long long>& markings,
         long long mark, vector<vector<long long>>& groups, long long i) {
    markings[i] = mark;
    groups[mark].push_back(i);
    for (long long j : adj[i]) {
        if (markings[j] == -1) {
            dfs(adj, markings, mark, groups, j);
        }
    }
}
void solve() {
    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> adj(N);
    for (long long i = 0; i < M; i++) {
        long long x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<long long> markings(N, -1);
    vector<vector<long long>> groups;
    long long mark = 0;
    for (long long i = 0; i < N; i++) {
        if (markings[i] == -1) {
            groups.push_back({});
            dfs(adj, markings, mark, groups, i);
            sort(groups[mark].begin(), groups[mark].end());
            mark++;
        }
    }
    if (markings[0] == markings[N - 1]) {
        cout << 0 << '\n';
        return;
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < mark; i++) {
        long long d_to_0 = min_dist(groups[i], groups[markings[0]]);
        long long d_to_N = min_dist(groups[i], groups[markings[N - 1]]);
        ans = min(ans, (d_to_0 + d_to_N));
    }
    cout << ans << '\n';
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}