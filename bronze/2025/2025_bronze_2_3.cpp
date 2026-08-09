#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for (int l = 1; l < j - i + 1; l++) {
                if ((j - i + 1) % l != 0) {
                    continue;
                }
                bool ok = true;
                for (int k = i; k <= j - l; k++) {
                    if (a[k] != a[k + l]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i][j] = min(dp[i][j], dp[i][i + l - 1]);
                    break;
                }
            }
        }
    }
    if (dp[0][N - 1] <= K) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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