#include <iostream>
#include <vector>
using namespace std;
long long find(int i, int j, vector<vector<long long>>& dp,
               vector<long long>& a) {
    if (i > j) {
        swap(i, j);
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (i == j) {
        dp[i][j] = a[i];
        return dp[i][j];
    }
    dp[i][j] = max(a[i] - find(i + 1, j, dp, a), a[j] - find(i, j - 1, dp, a));
    return dp[i][j];
}
int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> dp(N, vector<long long>(N, -1));
    cout << find(0, N - 1, dp, a) << '\n';
    return 0;
}