#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<long long> C(N);
    vector<long long> V(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> V[i];
        sum += V[i];
    }
    vector<long long> dp(sum + 1, 1e15);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j >= V[i]) {
                dp[j] = min(dp[j], dp[j - V[i]] + C[i]);
            } else {
                dp[j] = min(dp[j], C[i]);
            }
        }
    }

    for (int i = sum; i >= 0; i--) {
        if (dp[i] <= W) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}