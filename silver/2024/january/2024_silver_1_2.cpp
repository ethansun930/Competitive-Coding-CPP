#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& adj, vector<int>& collects,
         vector<int>& leaf_counts, unordered_set<int>& p, int node,
         int parent) {
    if (adj[node].size() == 1) {
        leaf_counts[node]++;
    }
    if (p.find(node) != p.end()) {
        collects[node]++;
    }
    for (const int& i : adj[node]) {
        if (i != parent) {
            DFS(adj, collects, leaf_counts, p, i, node);
            collects[node] += collects[i];
            leaf_counts[node] += leaf_counts[i];
        }
    }
    collects[node] = min(collects[node], leaf_counts[node]);
    cout << node << ' ' << leaf_counts[node] << ' ' << collects[node] << '\n';
}
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int min_travels = 0;
    for (int i = 0; i < N; i++) {
        if (adj[i].size() == 1) {
            min_travels++;
        }
    }
    vector<int> collects(N, 0);
    vector<int> leaf_counts(N, 0);
    unordered_set<int> new_p;
    for (int i = 0; i < min_travels; i++) {
        new_p.insert(p[i]);
    }
    for (int i = 0; i < N; i++) {
        DFS(adj, collects, leaf_counts, new_p, 0, -1);
    }
    cout << collects[0] << '\n';
}
