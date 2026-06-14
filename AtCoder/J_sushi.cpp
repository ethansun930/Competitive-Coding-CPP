#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    int amounts[3];
    amounts[0] = 0;
    amounts[1] = 0;
    amounts[2] = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            amounts[0]++;
        } else if (x == 2) {
            amounts[1]++;
        } else {
            amounts[2]++;
        }
    }
    vector<vector<vector<double>>> dp(
        N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, 0)));
    for (int k = 0; k <= N; k++) {
        for (int j = 0; j <= N; j++) {
            for (int i = 0; i <= N; i++) {
                if (i == 0 && j == 0 && k == 0) {
                    continue;
                }
                if (i + j + k > N) {
                    continue;
                }
                double amount = N;
                if (i > 0) {
                    amount += i * dp[i - 1][j][k];
                }
                if (j > 0) {
                    amount += j * dp[i + 1][j - 1][k];
                }
                if (k > 0) {
                    amount += k * dp[i][j + 1][k - 1];
                }
                dp[i][j][k] = amount / (i + j + k);
            }
        }
    }
    cout << setprecision(50) << dp[amounts[0]][amounts[1]][amounts[2]] << '\n';
    return 0;
}