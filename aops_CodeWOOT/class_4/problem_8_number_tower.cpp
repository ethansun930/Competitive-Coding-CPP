#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int H, V, T;
    cin >> H >> V >> T;
    if (T == 0) {
        vector<pair<long long, long long>> dp(H + 1, {0, 0});
        dp[0].first = 1;
        dp[0].second = 1;
        for (int i = 1; i <= H; i++) {
            if (i >= 2) {
                dp[i].second = dp[i - 2].first;
            }
            dp[i].first = dp[i - 1].second;
            if (V % 3 == 0 && i >= 2) {
                dp[i].first += dp[i - 2].second * 3;
            }
            if (V % 6 == 0 && i >= 2) {
                dp[i].first += dp[i - 2].second * 6;
            }
            if (V % 4 == 0 && i >= 3) {
                dp[i].first += dp[i - 3].second * 4;
            }
        }
        cout << dp[H].first + dp[H].second << '\n';
        return 0;
    }
    long long dp[103][6][8] = {};
    dp[0][0][0] = 1;
    int new_3[8] = {4, 5, 6, 7, 4, 5, 6, 7};
    int new_4[8] = {2, 3, 2, 3, 6, 7, 6, 7};
    int new_5[8] = {1, 1, 3, 3, 5, 5, 7, 7};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j <= 7; j++) {
            dp[i + 1][1][j] += dp[i][0][j] + dp[i][2][j];
            dp[i + 2][2][j] += dp[i][0][j] + dp[i][1][j] + dp[i][3][j] + dp[i][4][j] + dp[i][5][j];
            if (V % 3 == 0) {
                dp[i + 2][3][new_3[j]] += 3 * (dp[i][0][j] + dp[i][2][j]);
            }
            if (V % 6 == 0) {
                dp[i + 2][4][new_4[j]] += 6 * (dp[i][0][j] + dp[i][2][j]);
            }
            if (V % 4 == 0) {
                dp[i + 3][5][new_5[j]] += 4 * (dp[i][0][j] + dp[i][2][j]);
            }
        }
    }
    long long ans = 0;
    long long div[8] = {1, 4, 6, 12, 3, 12, 6, 12};
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 7; j++) {
            ans += (dp[H][i][j] / div[j]);
        }
    }
    cout << ans << '\n';
    return 0;
}