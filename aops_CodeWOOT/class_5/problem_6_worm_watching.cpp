#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void DFS(int node, vector<vector<int>>& children, vector<vector<int>>& dp) {
    int L = dp[node].size();
    dp[node][0] = 0;
    if (children[node].size() == 0) {
        dp[node][1] = 0;
    }
    for (int child : children[node]) {
        DFS(child, children, dp);
        vector<int> new_dp = dp[node];
        for (int i = 0; i < L; i++) {
            if (dp[node][i] == INT_MAX) {
                continue;
            }
            for (int j = 0; j < L; j++) {
                if (i + j > L) {
                    break;
                }
                if (dp[child][j] == INT_MAX) {
                    continue;
                }
                new_dp[i + j] = min(new_dp[i + j], dp[node][i] + dp[child][j] + 1);
            }
        }
        dp[node] = new_dp;
    }
}
int main() {
    int N, L;
    cin >> N >> L;
    vector<vector<int>> children(N);
    for (int i = 1; i < N; i++) {
        int j;
        cin >> j;
        j--;
        children[j].push_back(i);
    }
    vector<vector<int>> dp(N, vector<int>(L + 1, INT_MAX));
    DFS(0, children, dp);
    cout << 2 * dp[0][L] + L << '\n';
    return 0;
}