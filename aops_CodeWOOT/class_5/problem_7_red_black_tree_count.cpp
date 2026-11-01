#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<long long>> black_dp(N + 1, vector<long long>(N + 1, 0));
    vector<vector<long long>> red_dp(N + 1, vector<long long>(N + 1, 0));
    black_dp[0][0] = 1;
    for (int j = 0; j <= N; j++) {
        if (j >= 1) {
            for (int i = 1; i <= N; i++) {
                for (int k = 0; k < i; k++) {
                    black_dp[i][j] += (black_dp[k][j - 1] + red_dp[k][j - 1]) * (black_dp[i - k - 1][j - 1] + red_dp[i - k - 1][j - 1]);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int k = 0; k < i; k++) {
                red_dp[i][j] += black_dp[k][j] * black_dp[i - k - 1][j];
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += black_dp[N][i];
    }
    cout << ans << '\n';
}