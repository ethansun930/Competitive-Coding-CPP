#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void DFS(int node, vector<vector<int>>& children, vector<vector<int>>& dp, int L) {
    dp[node].push_back(0);
    if (children[node].size() == 0) {
        dp[node].push_back(0);
        return;
    }
    for (int child : children[node]) {
        DFS(child, children, dp, L);
        int new_size = min(L + 1, (int)dp[node].size() + (int)dp[child].size());
        for (int i = dp[node].size(); i < new_size; i++) {
            dp[node].push_back(INT_MAX);
        }
        vector<int> new_dp = dp[node];
        for (int i = 0; i < (int)dp[node].size(); i++) {
            if (dp[node][i] == INT_MAX) {
                continue;
            }
            for (int j = 0; j < (int)dp[child].size(); j++) {
                if (i + j > (int)dp[node].size()) {
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
    vector<vector<int>> dp(N);
    DFS(0, children, dp, L);
    cout << 2 * dp[0][L] + L << '\n';
    return 0;
}