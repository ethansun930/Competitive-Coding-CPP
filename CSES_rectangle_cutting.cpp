#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    dp[1][1] = 0;
    for (int i = 2; i <= a; i++) {
        dp[i][1] = 0;
    }
    for (int i = 1; i < b; i++) {
        dp[1][i] = 0;
    }
    for (int i = 1; i < a; i++) {
        for (int j = 1; j < b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 2147483647;
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k + 1] + 1);
            }
            for (int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k + 1][j] + 1);
            }
        }
    }
    cout << dp[a - 1][b - 1] << '\n';
    return 0;
}
/*
   0   1   2   3   4
0  0   0   0   0   0
1  0   0   1   2   3
2  0   1   0   2
*/
