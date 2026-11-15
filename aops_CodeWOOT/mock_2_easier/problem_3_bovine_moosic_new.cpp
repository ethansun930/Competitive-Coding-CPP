#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cfloat>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, H, S;
    cin >> V >> H >> S;
    vector<double> Y(V);
    for (int i = 0; i < V; i++) {
        cin >> Y[i];
    }
    vector<vector<double>> X(V, vector<double>(H));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < H; j++) {
            cin >> X[i][j];
        }
    }
    vector<double> B(S);
    for (int i = 0; i < S; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    vector<int> subsets;
    for (int i = 0; i < (1 << H); i++) {
        if (__builtin_popcount(i) == S) {
            subsets.push_back(i);
        }
    }
    int sub_count = subsets.size();
    vector<double> dp(sub_count, 0);
    for (int i = 0; i < sub_count; i++) {
        int curr_sub = subsets[i];
        for (int j = 0; j < S; j++) {
            double dx = B[j] - X[0][__builtin_ctz(curr_sub)];
            curr_sub -= (curr_sub & (-curr_sub));
            dp[i] += sqrt(dx * dx + Y[0] * Y[0]);
        }
    }
    vector<vector<double>> dis(H, vector<double>(H));
    for (int i = 1; i < V; i++) {
        vector<double> new_dp(sub_count, DBL_MAX);
        double dy = Y[i] - Y[i - 1];
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < H; k++) {
                double dx = X[i - 1][j] - X[i][k];
                dis[j][k] = sqrt(dx * dx + dy * dy);
            }
        }
        for (int j = 0; j < sub_count; j++) {
            for (int k = 0; k < sub_count; k++) {
                int old_sub = subsets[j];
                int new_sub = subsets[k];
                double curr_sum = 0;
                for (int i = 0; i < S; i++) {
                    curr_sum += dis[__builtin_ctz(old_sub)][__builtin_ctz(new_sub)];
                    old_sub -= (old_sub & -old_sub);
                    new_sub -= (new_sub & -new_sub);
                }
                new_dp[k] = min(new_dp[k], dp[j] + curr_sum);
            }
        }
        dp = new_dp;
    }
    double ans = DBL_MAX;
    for (int i = 0; i < sub_count; i++) {
        ans = min(ans, dp[i]);
    }
    cout << llround(ans) << '\n';
    return 0;
}