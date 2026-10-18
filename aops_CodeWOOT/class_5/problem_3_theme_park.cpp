#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
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
    vector<vector<int>> dp(1441, vector<int>(N + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < 721; i++) {
        if (dp[i][0] != -1) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
            for (pair<int, int> j : adj[0]) {
                dp[i + j.second][j.first] = max(dp[i + j.second][j.first], dp[i][0]);
            }
        }
        for (int j = 1; j <= N; j++) {
            if (next_s[j - 1] < S[j - 1] && t[j - 1][next_s[j - 1]] == i) {
                next_s[j - 1]++;
                if (dp[i][j] == -1) {
                    continue;
                }
                dp[i + X[j - 1]][j] = max(dp[i + X[j - 1]][j], dp[i][j] + 1);
            }
            if (dp[i][j] == -1) {
                continue;
            }
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            for (pair<int, int> k : adj[j]) {
                dp[i + k.second][k.first] = max(dp[i + k.second][k.first], dp[i][j]);
            }
        }
    }
    int ans = dp[0][0];
    int index = 0;
    for (int i = 1; i < 721; i++) {
        if (dp[i][0] > ans) {
            ans = dp[i][0];
            index = i;
        }
    }
    cout << ans << ' ' << index << '\n';
    return 0;
}