#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void finish_DFS(int node, vector<vector<int>>& adj, vector<int>& finishers, vector<bool>& visited) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    for (int child : adj[node]) {
        finish_DFS(child, adj, finishers, visited);
    }
    finishers.push_back(node);
}
void back_DFS(int node, vector<vector<int>>& adj, vector<int>& comp, int mark) {
    if (comp[node] != -1) {
        return;
    }
    comp[node] = mark;
    for (int child : adj[node]) {
        back_DFS(child, adj, comp, mark);
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<vector<int>> rev_adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    vector<int> finishers;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            finish_DFS(i, adj, finishers, visited);
        }
    }
    vector<int> comp(N, -1);
    int mark = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (comp[finishers[i]] == -1) {
            back_DFS(finishers[i], rev_adj, comp, mark);
            mark++;
        }
    }
    vector<int> in(mark, 0);
    vector<int> out(mark, 0);
    for (int i = 0; i < N; i++) {
        for (int j : adj[i]) {
            if (comp[i] != comp[j]) {
                out[comp[i]]++;
                in[comp[j]]++;
            }
        }
    }
    int in_node = 0;
    int out_node = 0;
    for (int i = 0; i < N; i++) {
        if (in[comp[i]] == 0) {
            in_node = i;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (out[comp[i]] == 0) {
            out_node = i;
            break;
        }
    }
    cout << out_node + 1 << ' ' << in_node + 1 << '\n';
    return 0;
}