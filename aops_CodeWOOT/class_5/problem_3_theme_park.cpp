#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> t(N);
    vector<int> X(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> S[i];
        for (int j = 0; j < S[i]; j++) {
            int T;
            cin >> T;
            t[i].push_back(T);
        }
    }
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }
    vector<int> next_s(N, 0);
    vector<vector<vector<bool>>> dp(1441, vector<vector<bool>>(N + 1, vector<bool>(1 << N, false)));
    dp[0][0][0] = true;
    for (int i = 0; i < 721; i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (!dp[i][0][j]) {
                continue;
            }
            dp[i + 1][0][j] = true;
            for (pair<int, int> k : adj[0]) {
                dp[i + k.second][k.first][j] = true;
            }
        }
        for (int j = 1; j <= N; j++) {
            if (next_s[j - 1] < S[j - 1] && t[j - 1][next_s[j - 1]] == i) {
                next_s[j - 1]++;
                for (int k = 0; k < (1 << N); k++) {
                    if ((k & (1 << (j - 1))) != 0) {
                        continue;
                    }
                    if (!dp[i][j][k]) {
                        continue;
                    }
                    dp[i + X[j - 1]][j][k | (1 << (j - 1))] = true;
                }
            }
            for (int k = 0; k < (1 << N); k++) {
                if (!dp[i][j][k]) {
                    continue;
                }
                dp[i + 1][j][k] = true;
                for (pair<int, int> l : adj[j]) {
                    dp[i + l.second][l.first][k] = true;
                }
            }
        }
    }
    int ans = 0;
    int time = 0;
    for (int j = 0; j < 721; j++) {
        for (int k = 0; k < (1 << N); k++) {
            if (dp[j][0][k] && __builtin_popcount(k) > ans) {
                ans = __builtin_popcount(k);
                time = j;
            }
        }
    }
    cout << ans << ' ' << time << '\n';
    return 0;
}