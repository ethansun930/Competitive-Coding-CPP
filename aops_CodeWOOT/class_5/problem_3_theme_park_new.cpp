#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> t(N);
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        int S;
        cin >> X[i] >> S;
        for (int j = 0; j < S; j++) {
            int T;
            cin >> T;
            t[i].push_back(T);
        }
    }
    vector<vector<int>> d(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i <= N; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        d[a][b] = p;
        d[b][a] = p;
    }
    for (int k = 0; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            if (d[i][k] == INT_MAX) {
                continue;
            }
            for (int j = 0; j <= N; j++) {
                if (d[k][j] == INT_MAX) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<vector<int>> next_ride(721, vector<int>(N));
    for (int i = 0; i < N; i++) {
        int next_index = 0;
        for (int j = 0; j < 721; j++) {
            if (next_index < t[i].size() && t[i][next_index] == j - 1) {
                next_index++;
            }
            if (next_index == t[i].size()) {
                next_ride[j][i] = INT_MAX;
                continue;
            }
            next_ride[j][i] = t[i][next_index];
        }
    }
    vector<vector<int>> dp(1 << N, vector<int>(N, INT_MAX));
    int ans = 0;
    int time = 0;
    for (int i = 0; i < N; i++) {
        if (d[i + 1][0] > 720) {
            continue;
        }
        int next_rides = next_ride[d[i + 1][0]][i];
        if (next_rides == INT_MAX) {
            continue;
        }
        if (next_rides + X[i] + d[i + 1][0] > 720) {
            continue;
        }
        dp[1 << i][i] = next_rides + X[i];
    }
    for (int j = 0; j < (1 << N); j++) {
        for (int i = 0; i < N; i++) {
            if (dp[j][i] == INT_MAX) {
                continue;
            }
            if (__builtin_popcount(j) > ans) {
                ans = __builtin_popcount(j);
                time = dp[j][i] + d[i + 1][0];
            }
            if (__builtin_popcount(j) == ans) {
                time = min(time, dp[j][i] + d[i + 1][0]);
            }
            for (int k = 0; k < N; k++) {
                if (i == k || (j & (1 << (k))) != 0) {
                    continue;
                }
                if (dp[j][i] + d[i + 1][k + 1] > 720) {
                    continue;
                }
                int next_rides = next_ride[dp[j][i] + d[i + 1][k + 1]][k];
                if (next_rides == INT_MAX) {
                    continue;
                }
                if (next_rides + X[k] + d[k + 1][0] > 720) {
                    continue;
                }
                dp[j | (1 << k)][k] = min(dp[j | (1 << k)][k], next_rides + X[k]);
            }
        }
    }
    cout << ans << ' ' << time << '\n';
    return 0;
}