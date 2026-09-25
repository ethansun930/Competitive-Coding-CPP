#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& adj, int i, vector<int>& finishers,
         vector<bool>& visited) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    for (const int& j : adj[i]) {
        DFS(adj, j, finishers, visited);
    }
    finishers.push_back(i);
}
void back_DFS(vector<vector<int>>& adj, int i, vector<bool>& visited) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    for (const int& j : adj[i]) {
        back_DFS(adj, j, visited);
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> front_adj(N);
    vector<vector<int>> back_adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        front_adj[a].push_back(b);
        back_adj[b].push_back(a);
    }
    vector<int> finishers;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(front_adj, i, finishers, visited);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    while (finishers.size() > 0) {
        int i = finishers.back();
        finishers.pop_back();
        if (visited[i]) {
            continue;
        }
        ans++;
        back_DFS(back_adj, i, visited);
    }
    cout << ans << '\n';
    return 0;
}