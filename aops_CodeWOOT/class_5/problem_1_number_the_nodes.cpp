#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct maxes {
    int mindex = -1;
    int m = INT_MAX;
    int s = INT_MAX;
    int maximum(int i) {
        if (i == mindex) {
            return s;
        }
        return m;
    }
    void add(int i, int n) {
        if (n <= m) {
            s = m;
            m = n;
            mindex = i;
        }
        else if (n <= s) {
            s = n;
        }
    }
};
void DFS(vector<vector<int>>& adj, vector<maxes>& dp, int node, int parent, int D) {
    if (parent != -1 && adj[node].size() == 1) {
        dp[node].m = 1;
        dp[node].mindex = 1;
        dp[node].s = 2;
        return;
    }
    for (const int& child : adj[node]) {
        if (child != parent) {
            DFS(adj, dp, child, node, D);
        }
    }
    for (int i = 0; i < D; i++) {
        int curr = i + 1;
        for (const int& child : adj[node]) {
            if (child != parent) {
                curr += dp[child].maximum(i + 1);
            }
        }
        dp[node].add(i + 1, curr);
    }
}
void comp_DFS(vector<vector<int>>& adj, vector<vector<vector<int>>>& dp, int node, int parent) {
    int D = dp[node].size();
    if (parent != -1 && adj[node].size() == 1) {
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                if (i != j) {
                    dp[node][i][j] = i + 1;
                }
            }
        }
        return;
    }
    for (int child : adj[node]) {
        if (child == parent) {
            continue;
        }
        comp_DFS(adj, dp, child, node);
    }
    for (int i = 0; i < D; i++) {
        vector<int> bdp(1 << D, INT_MAX);
        bdp[0] = 0;
        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }
            vector<int> new_dp(1 << D, INT_MAX);
            for (int j = 0; j < (1 << D); j++) {
                if (bdp[j] == INT_MAX) {
                    continue;
                }
                for (int k = 0; k < D; k++) {
                    if (k == i) {
                        continue;
                    }
                    if ((j & (1 << k)) != 0) {
                        continue;
                    }
                    if (dp[child][k][i] == INT_MAX) {
                        continue;
                    }
                    new_dp[j | (1 << k)] = min(new_dp[j | (1 << k)], bdp[j] + dp[child][k][i]);
                }
            }
            bdp = new_dp;
        }
        for (int j = 0; j < (1 << D); j++) {
            if (bdp[j] == INT_MAX) {
                continue;
            }
            if (parent == -1) {
                dp[node][i][0] = min(dp[node][i][0], bdp[j] + i + 1);
                continue;
            }
            for (int k = 0; k < D; k++) {
                if (k == i) {
                    continue;
                }
                if ((j & (1 << k)) != 0) {
                    continue;
                }
                dp[node][i][k] = min(dp[node][i][k], bdp[j] + i + 1);
            }
        }
    }
}
int main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (K == 1) {
        vector<maxes> dp(N);
        DFS(adj, dp, 0, -1, D);
        cout << dp[0].m << '\n';
        return 0;
    }
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(D, vector<int>(D, INT_MAX)));
    comp_DFS(adj, dp, 0, -1);
    int ans = INT_MAX;
    for (int i = 0; i < D; i++) {
        ans = min(ans, dp[0][i][0]);
    }
    cout << ans << '\n';
    return 0;
}
