#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void DFS(long long node, long long parent, vector<vector<pair<long long, long long>>>& adj, vector<long long>& size) {
    if (adj[node].size() == 1 && parent != -1) {
        return;
    }
    for (pair<long long, long long> child : adj[node]) {
        if (child.first == parent) {
            continue;
        }
        DFS(child.first, node, adj, size);
        size[node] += size[child.first];
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
    vector<long long> size(N, 1);
    DFS(0, -1, adj, size);
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        for (pair<long long, long long> j : adj[i]) {
            if (size[j.first] > size[i]) {
                continue;
            }
            ans += size[j.first] * (N - size[j.first]) * j.second;
        }
    }
    cout << ans << '\n';
    return 0;
}