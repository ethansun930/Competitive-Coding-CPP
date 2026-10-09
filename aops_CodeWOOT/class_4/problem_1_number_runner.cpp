#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> num(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    vector<long long> dp(K + 1, LLONG_MIN);
    dp[0] = 0;
    vector<long long> new_dp(K + 1, LLONG_MIN);
    for (int i = 0; i < N; i++) {
        new_dp[0] = dp[0] + num[i];
        long long curr_num = num[i];
        for (int j = 1; j <= K; j++) {
            new_dp[j] = LLONG_MIN;
            curr_num = -curr_num;
            if (dp[j - 1] != LLONG_MIN) {
                new_dp[j] = dp[j - 1] + curr_num;
            }
            if (dp[j] != LLONG_MIN) {
                new_dp[j] = max(new_dp[j], dp[j] + curr_num);
            }
        }
        dp = new_dp;
    }
    long long ans = LLONG_MIN;
    for (int i = 0; i <= K; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}