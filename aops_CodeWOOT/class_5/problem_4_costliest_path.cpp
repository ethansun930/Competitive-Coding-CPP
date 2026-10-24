#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void DFS(int node, vector<int>& dp, vector<vector<int>>& children, vector<int>& cost) {
    int ans = 0;
    for (int child : children[node]) {
        DFS(child, dp, children, cost);
        if (dp[child] + cost[child] > ans) {
            ans = dp[child] + cost[child];
        }
    }
    dp[node] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<vector<int>> children (N, vector<int>());
        for (int i = 1; i < N; i++) {
            int p;
            cin >> p;
            p--;
            children[p].push_back(i);
        }
        vector<int> cost(N, 0);
        for (int i = 1; i < N; i++) {
            cin >> cost[i];
        }
        vector<int> dp(N);
        int m = 0;
        int s = 0;
        for (int i : children[0]) {
            DFS(i, dp, children, cost);
            if (dp[i] + cost[i] >= m) {
                s = m;
                m = dp[i] + cost[i];
            }
            else if (dp[i] + cost[i] > s) {
                s = dp[i] + cost[i];
            }
        }
        cout << m + s << '\n';
    }
    return 0;
}