#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<long long>& a, int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    return a[y + 1] - a[x];
}
int main() {
    int N;
    cin >> N;
    vector<long long> a(N + 1);
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            int x = j;
            int y = i + j;
            if (x == y) {
                dp[x][y] = 0;
                continue;
            }
            dp[x][y] = 9223372036854775807;
            for (int k = x; k < y; k++) {
                dp[x][y] =
                    min(dp[x][y], dp[x][k] + dp[k + 1][y] + sum(a, x, y));
            }
        }
    }
    cout << dp[0][N - 1];
    return 0;
}