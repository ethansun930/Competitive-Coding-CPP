#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int l1, l2, C, D, I;
    cin >> l1 >> l2 >> C >> D >> I;
    string S1;
    string S2;
    cin >> S1 >> S2;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; i++) {
        dp[i][0] = i * D;
    }   
    for (int i = 1; i <= l2; i++) {
        dp[0][i] = i * I;
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            dp[i][j] = INT_MAX;
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + C);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + D);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + I);
        }
    }
    cout << dp[l1][l2] << '\n';
    return 0;
}