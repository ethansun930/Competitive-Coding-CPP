#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int V, H, S;
    cin >> V >> H >> S;
    vector<long long> Y(V);
    for (int i = 0; i < V; i++) {
        cin >> Y[i];
    }
    vector<vector<long long>> X(V, vector<long long>(H));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < H; j++) {
            cin >> X[i][j];
        }
    }
    vector<long long> B(S);
    for (int i = 0; i < S; i++) {
        cin >> B[i];
    }
    vector<long double> dp(1 << H, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < S; i++) {
        vector<long double> new_dp(1 << H, LLONG_MAX);
        for (int j = 0; j < (1 << H); j++) {
            if (dp[j] == LLONG_MAX) {
                continue;
            }
            for (int k = 0; k < H; k++) {
                if ((j & (1 << k)) != 0) {
                    continue;
                }
                long double d = (X[0][k] - B[i]) * (X[0][k] - B[i]) + (Y[0] * Y[0]);
                new_dp[j | (1 << k)] = min(new_dp[j | (1 < k)], dp[j] + sqrt(d));
            }
        }
        dp = new_dp;
    }
    for (int i = 1; i < V; i++) {
        vector<long double> newed_dp(1 << H, LLONG_MAX);
        for (int mask = 0; mask < (1 << H); mask++) {
            if (dp[mask] == LLONG_MAX) {
                continue;
            }
            vector<long long> prev_pos;
            for (int j = 0; j < H; j++) {
                if ((mask & (1 << j)) != 0) {
                    prev_pos.push_back(X[i - 1][j]);
                }
            }
            vector<long double> next_dp(1 << H, LLONG_MAX);
            next_dp[0] = dp[mask];
            for (int j = 0; j < S; j++) {
                vector<long double> new_dp(1 << H, LLONG_MAX);
                for (int k = 0; k < (1 << H); k++) {
                    if (next_dp[k] == LLONG_MAX) {
                        continue;
                    }
                    for (int l = 0; l < H; l++) {
                        if (k & (1 << l) != 0) {
                            continue;
                        }
                        long double d = (X[i][l] - prev_pos[i]) * (X[i][l] - prev_pos[i]) + (Y[i] - Y[i - 1]) * (Y[i] - Y[i - 1]);
                        new_dp[k | (1 << l)] = min(new_dp[k | (1 << l)], dp[k] + sqrt(d));
                    }
                }
                next_dp = new_dp;
            }
            for (int j = 0; j < (1 << H); j++) {
                newed_dp[j] = min(newed_dp[j], next_dp[j]);
            }
        }
        dp = newed_dp;
    }
    long double ans = LLONG_MAX;
    for (int i = 0; i < (1 << H); i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}