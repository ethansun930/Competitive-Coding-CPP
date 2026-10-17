#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, M, T, K;
    cin >> N >> M >> T >> K;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(T + 1, vector<int>(N, 0));
    dp[0][0] = 1;
    vector<int> prefix(N, 0);
    prefix[0] = 1;
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < N; j++) {
            for (int k : adj[j]) {
                dp[i][j] += prefix[k];
                dp[i][j] %= 1000000007;
            }
        }
        for (int j = 0; j < N; j++) {
            prefix[j] += dp[i][j];
            prefix[j] %= 1000000007;
            if (i >= K + 1) {
                prefix[j] -= dp[i - K - 1][j];
                prefix[j] = (prefix[j]%1000000007 + 1000000007)%1000000007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += prefix[i];
        ans %= 1000000007;
    }
    cout << ans << '\n';
    return 0;
}