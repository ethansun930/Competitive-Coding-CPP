#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long L, K;
    cin >> L >> K;
    vector<long long> P;
    vector<long long> T;
    for (long long i = 0; i < K; i++) {
        long long n, p, t;
        cin >> n >> p >> t;
        long long j = 0;
        while (n >= (1 << j)) {
            P.push_back((1 << j) * p);
            T.push_back((1 << j) * t);
            n -= (1 << j);
            j++;
        }
        P.push_back(n * p);
        T.push_back(n * t);
    }
    vector<long long> dp(L + 1, 0);
    long long N = P.size();
    for (long long i = 0; i < N; i++) {
        for (long long j = L; j >= T[i]; j--) {
            dp[j] = max(dp[j], dp[j - T[i]] + P[i]);
        }
    }
    cout << dp[L] << '\n';
    return 0;
}