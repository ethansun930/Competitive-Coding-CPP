#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;;

int main() {
    int K;
    double S;
    cin >> K >> S;
    double B[9];
    for (int i = 0; i < 9; i++) {
        cin >> B[i];
    }
    double expect = 0;
    int best[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int P[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    do {
        double dp[101][4][3] = {{{0}}};
        for (int k = K - 1; k >= 0; k--) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 3) {
                        dp[k][i][j] += B[P[k%9]] * (1 + dp[k + 1][3][j]);
                    }
                    else {
                        dp[k][i][j] += B[P[k%9]] * dp[k + 1][i + 1][j];
                    }
                    if (j == 2) {
                        dp[k][i][j] += (1 - B[P[k%9]]) * dp[k + 1][0][0];
                    }
                    else {
                        dp[k][i][j] += (1 - B[P[k%9]]) * dp[k + 1][i][j + 1];
                    }
                }
            }
        }
        if (dp[0][0][0] - expect > S/2.0) {
            for (int i = 0; i < 9; i++) {
                best[i] = P[i];
            }
            expect = dp[0][0][0];
        }
    }
    while (next_permutation(begin(P), end(P)));
    for (int i = 0; i < 8; i++) {
        cout << best[i] + 1 << ' ';
    }
    cout << best[8] + 1 << '\n';
    return 0;
}