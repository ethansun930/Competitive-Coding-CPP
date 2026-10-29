#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void DFS(int node, vector<long long>& dp, vector<vector<int>>& children, vector<long long>& cost, long long& answer) {
    long long ans = 0;
    long long second = 0;
    for (int child : children[node]) {
        DFS(child, dp, children, cost, answer);
        if (dp[child] + cost[child] >= ans) {
            second = ans;
            ans = dp[child] + cost[child];
        }
        else if (dp[child] + cost[child] > second) {
            second = dp[child] + cost[child];
        }
    }
    dp[node] = ans;
    answer = max(answer, ans + second);
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
        vector<long long> cost(N, 0);
        for (int i = 1; i < N; i++) {
            cin >> cost[i];
        }
        vector<long long> dp(N);
        long long answer = 0;
        DFS(0, dp, children, cost, answer);
        cout << answer << '\n';
    }
    return 0;
}