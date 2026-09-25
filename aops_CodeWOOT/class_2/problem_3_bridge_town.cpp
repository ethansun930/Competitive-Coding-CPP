#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& dis, vector<int>& low, vector<bool>& visited, int& time, int& ans) {
    visited[node] = true;
    dis[node] = time;
    low[node] = time;
    time++;
    for (int child : adj[node]) {
        if (child == parent) {
            continue;
        }
        if (visited[child]) {
            low[node] = min(low[node], dis[child]);
        }
        else {
            dfs(child, node, adj, dis, low, visited, time, ans);
            low[node] = min(low[node], low[child]);
            if (low[child] > dis[node]) {
                ans++;
            }
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dis(N, -1);
    vector<int> low(N, -1);
    vector<bool> visited(N, false);
    int time = 0;
    int ans = 0;
    dfs(0, -1, adj, dis, low, visited, time, ans);
    cout << ans << '\n';
    return 0;
}