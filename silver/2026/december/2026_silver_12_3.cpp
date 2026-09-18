#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string b;
    cin >> b;
    vector<int> r(N - K + 1, 0);
    for (int i = 0; i < N - K + 1; i++) {
        r[i] = b[i] - '0';
    }
    vector<int> d(N, 0);
    vector<int> pick_0(K, 0);
    vector<int> pick_1(K, 1);
    for (int i = 0; i < N - K; i++) {
        d[i + K] = (d[i] + r[i + 1] - r[i] + 2) % 2;
        pick_0[i % K] += d[i + K];
        pick_1[i % K] += (1 - d[i + K]);
    }
    vector<pair<int, int>> min_dp(K);
    min_dp[0].first = pick_0[0];
    min_dp[0].second = pick_1[0];
    for (int i = 1; i < K; i++) {
        min_dp[i].first = min(min_dp[i - 1].first + pick_0[i],
                              min_dp[i - 1].second + pick_1[i]);
        min_dp[i].second = min(min_dp[i - 1].first + pick_1[i],
                               min_dp[i - 1].second + pick_0[i]);
    }
    if (r[0] == 0) {
        cout << min_dp[K - 1].first << ' ';
    } else {
        cout << min_dp[K - 1].second << ' ';
    }
    vector<pair<int, int>> max_dp(K);
    max_dp[0].first = pick_0[0];
    max_dp[0].second = pick_1[0];
    for (int i = 1; i < K; i++) {
        max_dp[i].first = max(max_dp[i - 1].first + pick_0[i],
                              max_dp[i - 1].second + pick_1[i]);
        max_dp[i].second = max(max_dp[i - 1].first + pick_1[i],
                               max_dp[i - 1].second + pick_0[i]);
    }
    if (r[0] == 0) {
        cout << max_dp[K - 1].first << '\n';
    } else {
        cout << max_dp[K - 1].second << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}