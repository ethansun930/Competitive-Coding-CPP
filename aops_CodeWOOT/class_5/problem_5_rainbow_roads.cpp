#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

struct Road {
    int b, r, s;
};
struct State {
    int pos, color, cost;
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> D[i];
        C[i]--;
    }
    vector<vector<Road>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b, s;
        string r;
        cin >> a >> b >> r >> s;
        a--;
        b--;
        int int_r = 0;
        for (int i = 5; i >= 0; i--) {
            int_r <<= 1;
            if (r[i] == '1') {
                int_r += 1;
            }
        }
        adj[a].push_back({b, int_r, s});
        adj[b].push_back({a, int_r, s});
    }
    vector<int> dp[64];
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < N; j++) {
            dp[i].push_back(INT_MAX);
        }
    }
    for (int i = 0; i < N - 1; i++) {
        dp[0][i] = 0;
    }
    queue<State> q;
    for (int i = 0; i < N - 1; i++) {
        q.push({i, 0, 0});
    }
    while (!q.empty()) {
        State node = q.front();
        q.pop();
        if (dp[node.color][node.pos] < node.cost) {
            continue;
        }
        if (C[node.pos] != -1) {
            if ((node.color & (1 << C[node.pos])) == 0) {
                int new_color = (node.color | (1 << C[node.pos])); 
                int new_pos = node.pos;
                int new_cost = node.cost + D[node.pos];
                if (dp[new_color][new_pos] > new_cost) {
                    dp[new_color][new_pos] = new_cost;
                    q.push({new_pos, new_color, new_cost});
                }
            }
        }
        for (Road j : adj[node.pos]) {
            if ((node.color & j.r) == j.r) {
                int new_color = node.color;
                int new_pos = j.b;
                int new_cost = node.cost + j.s;
                if (dp[new_color][new_pos] > new_cost) {
                    dp[new_color][new_pos] = new_cost;
                    q.push({new_pos, new_color, new_cost});
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 64; i++) {
        ans = min(ans, dp[i][N - 1]);
    }
    cout << ans << '\n';
    return 0;
}