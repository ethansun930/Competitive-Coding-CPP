#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& matched,
         int& ans) {
    for (int child : adj[node]) {
        if (child == parent) {
            continue;
        }
        dfs(child, node, adj, matched, ans);
        if (!matched[child] && !matched[node]) {
            ans++;
            matched[child] = true;
            matched[node] = true;
        }
    }
    return;
}
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    vector<bool> matched(n, false);
    dfs(0, -1, adj, matched, ans);
    cout << ans << '\n';
    return 0;
}