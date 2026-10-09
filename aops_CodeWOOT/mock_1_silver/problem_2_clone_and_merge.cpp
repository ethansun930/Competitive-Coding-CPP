#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 2;
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j] + 2);
            if (i < 2 * j) {
                dp[i] = min(dp[i], dp[i - j] + dp[2 * j - i] + 4);
            }
        }
        for (int j = 1; j * j <= i; j++) {
            if (i%j == 0) {
                dp[i] = min(dp[i], dp[j] + dp[i/j]);
            }
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
/*
1
1 1
1 1 1
2 1
3
3 3
3 3 3
6 3
6 6 3
12 3
15
*/