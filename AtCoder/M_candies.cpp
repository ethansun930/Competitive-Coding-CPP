#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        vector<long long> sums(K + 1, 1);
        for (int j = 1; j <= K; j++) {
            sums[j] = sums[j - 1] + dp[i - 1][j];
            sums[j] %= 1000000007;
        }
        for (int j = 0; j <= K; j++) {
            if (j <= a[i - 1]) {
                dp[i][j] = sums[j];
            } else {
                dp[i][j] = sums[j] - sums[j - a[i - 1] - 1] + 1000000007;
                dp[i][j] %= 1000000007;
            }
        }
    }
    cout << dp[N][K] << '\n';
    return 0;
}