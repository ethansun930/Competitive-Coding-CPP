#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int cow;
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> f(N);
    vector<int> s(N);
    vector<vector<Edge>> adj(M);
    for (int i = 0; i < N; i++) {
        cin >> f[i] >> s[i];
        f[i]--;
        s[i]--;
        adj[f[i]].push_back({s[i], i});
        adj[s[i]].push_back({f[i], i});
    }
    vector<bool> visited_vertex(M, false);
    vector<bool> visited_edge(N, false);
    vector<bool> happy_cow(N, false);
    vector<int> order;
    for (int i = 0; i < M; i++) {
        if (visited_vertex[i]) {
            continue;
        }
        visited_vertex[i] = true;
        vector<vector<Edge>> span_tree_adj(M + 1);
        vector<int> sad_cows;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (Edge& edge : adj[node]) {
                if (visited_edge[edge.cow]) {
                    continue;
                }
                visited_edge[edge.cow] = true;
                if (!visited_vertex[edge.to]) {
                    visited_vertex[edge.to] = true;
                    q.push(edge.to);
                    span_tree_adj[node].push_back(edge);
                    span_tree_adj[edge.to].push_back({node, edge.cow});
                } else {
                    sad_cows.push_back(edge.cow);
                }
            }
        }
        int root = i;
        if (!sad_cows.empty()) {
            order.push_back(sad_cows[0]);
            happy_cow[sad_cows[0]] = true;
            root = f[sad_cows[0]];
        }
        vector<bool> new_visited(M, false);
        q = queue<int>();
        q.push(root);
        new_visited[root] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (Edge& edge : span_tree_adj[node]) {
                if (new_visited[edge.to]) {
                    continue;
                }
                new_visited[edge.to] = true;
                order.push_back(edge.cow);
                q.push(edge.to);
                happy_cow[edge.cow] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!happy_cow[i]) {
            ans++;
            order.push_back(i);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < N; i++) {
        cout << order[i] + 1 << '\n';
    }
    return 0;
}