#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<climits>
using namespace std;

int all = 0;
map<vector<int>, int> memo;
int colors(vector<int>& adj, vector<int>& power) {
    if (memo.find(adj) != memo.end()) {
        return memo[adj];
    }
    int N = adj.size();
    for (int i = 0; i < N; i++) {
        if (adj[i] == INT_MAX) {
            continue;
        }
        if (adj[i] == 0) {
            continue;
        }
        int j = __builtin_ctz(adj[i]);
        adj[i] &= (all - (1 << j));
        adj[j] &= (all - (1 << i));
        int curr = colors(adj, power);
        adj[i] |= (1 << j);
        adj[j] |= (1 << i);
        vector<int> new_adj(N);
        for (int k = 0; k < N; k++) {
            if (k == j) {
                new_adj[k] = INT_MAX;
            }
            else {
                new_adj[k] = adj[k];
            }
        }
        for (int k = 0; k < N; k++) {
            if ((adj[j] & (1 << k)) == 0) {
                continue;
            }
            new_adj[k] &= (all - (1 << j));
            if (k != i) {
              new_adj[k] |= (1 << i);
                new_adj[i] |= (1 << k);
            }
        }
        memo[adj] = (curr - colors(new_adj, power) + 1000000007)%1000000007;
        return memo[adj];
    }
    int vertices_left = 0;
    for (int i = 0; i < N; i++) {
        if (adj[i] != INT_MAX) {
            vertices_left++;
        }
    }
    memo[adj] = power[vertices_left];
    return power[vertices_left];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, C;
    cin >> N >> M >> C;
    all = (1 << N) - 1;
    vector<int> adj(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }
    vector<int> power(N + 1, 1);
    long long x = 1;
    for (int i = 0; i <= N; i++) {
        power[i] = (int)x;
        x *= C;
        x %= 1000000007;
    }
    cout << colors(adj, power) << '\n';
    return 0;
}