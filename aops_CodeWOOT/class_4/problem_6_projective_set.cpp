#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cards(M, 0);
    for (int i = 0; i < M; i++) {
        string S;
        cin >> S;
        int length = S.length();
        for (int j = 0; j < length; j++) {
            cards[i] += (1 << (S[j] - 'A'));
        }
    }
    vector<long long> dp[4]{
        vector<long long>(1 << N, 0),
        vector<long long>(1 << N, 0),
        vector<long long>(1 << N, 0),
        vector<long long>(1 << N, 0)
    };
    dp[0][0] = 1;
    for (int i = 0; i < M; i++) {
        vector<long long> new_dp[4]{
            vector<long long>(1 << N, 0),
            vector<long long>(1 << N, 0),
            vector<long long>(1 << N, 0),
            vector<long long>(1 << N, 0)
        };
        new_dp[0][0] = 1;
        for (int j = 0; j < (1 << N); j++) {
            new_dp[1][j] = dp[1][j] + dp[0][j ^ cards[i]];
            new_dp[2][j] = dp[2][j] + dp[1][j ^ cards[i]];
            new_dp[3][j] = dp[3][j] + dp[2][j ^ cards[i]] + dp[3][j ^ cards[i]];
        }
        dp[0] = new_dp[0];
        dp[1] = new_dp[1];
        dp[2] = new_dp[2];
        dp[3] = new_dp[3]; 
    }
    cout << dp[3][0] << '\n';
    return 0;
}