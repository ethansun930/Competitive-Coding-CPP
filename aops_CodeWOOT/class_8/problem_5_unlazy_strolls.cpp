#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, int parent, vector<vector<int>>& adj, vector<vector<int>>& jump, vector<int>& depth) {
    jump[node][0] = parent;
    for (int child : adj[node]) {
        if (child == parent) {
            continue;
        }
        depth[child] = depth[node] + 1;
        DFS(child, node, adj, jump, depth);
    }
}
int dist(int a, int b, vector<int>& depth, vector<vector<int>>& jump) {
    int new_a = a;
    int new_b = b;
    if (depth[new_a] < depth[new_b]) {
        swap(new_a, new_b);
    }
    for (int i = 19; i >= 0; i--) {
        if (depth[jump[new_a][i]] >= depth[new_b]) {
            new_a = jump[new_a][i];
        }
    }
    int lca = new_a;
    if (new_a != new_b) {
        for (int i = 19; i >= 0; i--) {
            if (jump[new_a][i] == jump[new_b][i]) {
                lca = jump[new_a][i];
            }
            else {
                new_a = jump[new_a][i];
                new_b = jump[new_b][i];
            }
        }
    }
    return depth[a] + depth[b] - 2 * depth[lca];
}
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(N, 0);
    vector<vector<int>> jump(N, vector<int>(20));
    DFS(0, 0, adj, jump, depth);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < N; j++) {
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }
    for (int q = 0; q < Q; q++) {
        int c, d, t, s, f;
        cin >> c >> d >> t >> s >> f;
        c--;
        d--;
        s--;
        f--;
        int ans = dist(s, f, depth, jump);
        if (ans <= t && (t - ans)%2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        ans = dist(s, c, depth, jump) + 1 + dist(d, f, depth, jump);
        if (ans <= t && (t - ans)%2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        ans = dist(s, d, depth, jump) + 1 + dist(c, f, depth, jump);
        if (ans <= t && (t - ans)%2 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return;
}
int main() {
    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}