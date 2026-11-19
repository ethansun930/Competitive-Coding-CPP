#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void DFS(long long node, long long parent, vector<vector<pair<long long, long long>>>& adj, vector<long long>& sizes, vector<long long>& sums) {
    if (adj[node].size() == 1 && parent != -1) {
        return;
    }
    for (pair<long long, long long> child : adj[node]) {
        if (child.first == parent) {
            continue;
        }
        DFS(child.first, node, adj, sizes, sums);
        sizes[node] += sizes[child.first];
        sums[node] += sums[child.first];
        sums[node] += child.second * sizes[child.first];
        sums[child.first] = 0;
    }
}
void sums_DFS(long long node, long long parent, vector<vector<pair<long long, long long>>>& adj, vector<long long>& sizes, vector<long long>& sums) {
    int N = adj.size();
    for (pair<long long, long long> child : adj[node]) {
        if (child.first == parent) {
            continue;
        }
        sums[child.first] = sums[node] + (N - 2 * sizes[child.first]) * child.second;
        sums_DFS(child.first, node, adj, sizes, sums);
    }
}
int main() {
    long long N;
    cin >> N;
    vector<vector<pair<long long, long long>>> adj(N);
    for (long long i = 0; i < N - 1; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<long long> sizes(N, 1);
    vector<long long> sums(N, 0);
    DFS(0, -1, adj, sizes, sums);
    sums_DFS(0, -1, adj, sizes, sums);
    for (int i = 0; i < N; i++) {
        cout << sums[i] << '\n';
    }
    return 0;
}