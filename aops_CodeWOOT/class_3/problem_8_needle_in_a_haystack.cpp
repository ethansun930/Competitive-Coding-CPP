#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int l) {
        for (int i = 0; i < l; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int i, int j) {
        if (find(i) == find(j)) {
            return;
        }
        if (size[find(i)] <= size[find(j)]) {
            size[find(j)] += size[find(i)];
            parent[find(i)] = find(j);
        }
        else {
            size[find(i)] += size[find(j)];
            parent[find(j)] = find(i);
        }
    }
};
struct Edge {
    int a, b;
    bool operator<(const Edge& other) const {
        if (a != other.a) {
            return a < other.a;
        }
        return b < other.b;
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> tree_edge;
    vector<Edge> cycle_edge;
    vector<vector<int>> adj(N);
    DSU dsu = DSU(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dsu.find(a) == dsu.find(b)) {
            cycle_edge.push_back({a, b});
        }
        else {
            dsu.merge(a, b);
            tree_edge.push_back({a, b});
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    vector<int> parent(N, -1);
    vector<int> depth(N, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int child : adj[node]) {
            if (child == parent[node]) {
                continue;
            }
            parent[child] = node;
            depth[child] = depth[node] + 1;
            q.push(child);
        }
    }
    map<Edge, bool> in_cycle;
    for (const Edge& e : tree_edge) {
        in_cycle[e] = false;
    }
    for (const Edge& e : cycle_edge) {
        int a = e.a;
        int b = e.b;
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        while (depth[a] != depth[b]) {
            in_cycle[{min(b, parent[b]), max(b, parent[b])}] = true;
            b = parent[b];
        }
        while (a != b) {
            in_cycle[{min(a, parent[a]), max(a, parent[a])}] = true;
            a = parent[a];
            in_cycle[{min(b, parent[b]), max(b, parent[b])}] = true;
            b = parent[b];
        }
    }
    for (const pair<const Edge, bool>& e : in_cycle) {
        if (!e.second) {
            cout << e.first.a + 1 << ' ' << e.first.b + 1 << '\n';
        }
    }
    return 0;
}