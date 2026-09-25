#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(int i, vector<vector<int>>& adj, vector<int>& finishers, vector<bool>& visited) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    for (int j : adj[i]) {
        DFS(j, adj, finishers, visited);
    }
    finishers.push_back(i);
}
void back_DFS(int i, vector<vector<int>>& adj, vector<int>& marks, int mark) {
    if (marks[i] != -1) {
        return;
    }
    marks[i] = mark;
    for (int j : adj[i]) {
        back_DFS(j, adj, marks, mark);
    }
}
void solve() {
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
            DFS(i, adj, finishers, visited);
        }
    }
    vector<int> marks(N, -1);
    int mark = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (marks[finishers[i]] == -1) {
            back_DFS(finishers[i], rev_adj, marks, mark);
            mark++;
        }
    }
    if (mark == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<int> in(mark, 0);
    vector<int> out(mark, 0);
    for (int i = 0; i < N; i++) {
        for (int j : adj[i]) {
            if (marks[i] == marks[j]) {
                continue;
            }
            in[marks[j]]++;
            out[marks[i]]++;
        }
    }
    int in_count = 0;
    int out_count = 0;
    for (int i = 0; i < mark; i++) {
        if (in[i] == 0) {
            in_count++;
        }
        if (out[i] == 0) {
            out_count++;
        }
    }
    cout << max(in_count, out_count) << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}