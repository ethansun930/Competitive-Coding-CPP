#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;
    long long dp[7] = {0};
    long long ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'b') {
            dp[1]++;
            dp[1] += dp[0];
            dp[0] = 0;
        } else if (S[i] == 'e') {
            dp[2] += dp[1];
            dp[1] = 0;
            dp[0] += dp[5];
            dp[6] += dp[5];
            dp[5] = 0;
            dp[0]++;
        } else if (S[i] == 's') {
            dp[4] += dp[3];
            dp[3] = 0;
            dp[3] += dp[2];
            dp[2] = 0;
            dp[0]++;
        } else if (S[i] == 'i') {
            dp[5] += dp[4];
            dp[4] = 0;
            dp[0]++;
        } else {
            dp[0]++;
        }
        ans += dp[6];
    }
    cout << ans << '\n';
    return 0;
}
