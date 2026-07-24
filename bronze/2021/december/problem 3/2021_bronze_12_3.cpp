#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < N; j++) {
            if (x[j] == 'H') {
                grid[i][j] = 1;
            }
        }
    }
    if (grid[0][0] == 1) {
        cout << "0" << '\n';
        return;
    }
    vector<vector<vector<vector<int>>>> dp(
        N, vector<vector<vector<int>>>(
               N, vector<vector<int>>(K + 1, vector<int>(2, 0))));
    if (grid[0][1] == 0) {
        dp[0][1][0][0] = 1;
    }
    if (grid[1][0] == 0) {
        dp[1][0][0][1] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                for (int k = 0; k <= K; k++) {
                    if (j > 0) {
                        dp[i][j][k][0] += dp[i][j - 1][k][0];
                        if (k > 0) {
                            dp[i][j][k][0] += dp[i][j - 1][k - 1][1];
                        }
                    }
                    if (i > 0) {
                        dp[i][j][k][1] += dp[i - 1][j][k][1];
                        if (k > 0) {
                            dp[i][j][k][1] += dp[i - 1][j][k - 1][0];
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= K; i++) {
        ans += dp[N - 1][N - 1][i][0];
        ans += dp[N - 1][N - 1][i][1];
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