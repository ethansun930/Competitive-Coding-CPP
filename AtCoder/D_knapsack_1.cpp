#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<long long> C(N);
    vector<long long> V(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> V[i];
    }
    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= C[i]; j--) {
            dp[j] = max(dp[j], dp[j - C[i]] + V[i]);
        }
    }
    cout << dp[W] << '\n';
    return 0;
}