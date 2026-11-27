#include<iostream>
#include<vector>
using namespace std;

void down_DFS(int node, vector<int>& parent, vector<vector<int>>& adj, vector<long long>& down, vector<long long>& up) {
    int childs = adj[node].size() - 1;
    if (node == 0) {
        childs++;
    }
    vector<long long> prefix(childs + 1, 1);
    vector<long long> suffix(childs + 1, 1);
    vector<long long> values(childs);
    vector<int> children;
    int adj_size = adj[node].size();
    for (int i = 0; i < adj_size; i++) {
        int child = adj[node][i];
        if (child == parent[node]) {
            continue;
        }
        children.push_back(child);
    }
    for (int i = 0; i < childs; i++) {
        int child = children[i];
        parent[child] = node;
        down_DFS(child, parent, adj, down, up);
        down[node] *= (down[child] + 1);
        down[node] %= 1000000007;
        values[i] = down[child] + 1;
        prefix[i + 1] = (prefix[i] * values[i])%1000000007;
    }
    for (int i = childs - 1; i >= 0; i--) {
        suffix[i] = (suffix[i + 1] * values[i])%1000000007;
    }
    for (int i = 0; i < childs; i++) {
        int child = children[i];
        up[child] = (prefix[i] * suffix[i + 1])%1000000007;
    }
}
void up_DFS(int node, vector<int>& parent, vector<vector<int>>& adj, vector<long long>& up) {
    for (int child : adj[node]) {
        if (child == parent[node]) {
            continue;
        }
        up[child] *= up[node];
        up[child]++;
        up[child] %= 1000000007;
        up_DFS(child, parent, adj, up);
    }
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(N, 0);
    vector<long long> down(N, 1);
    vector<long long> up(N, 1);
    down_DFS(0, parent, adj, down, up);
    up_DFS(0, parent, adj, up);
    for (int i = 0; i < N; i++) {
        cout << (down[i] * up[i])%1000000007 << '\n';
    }
    return 0;
}