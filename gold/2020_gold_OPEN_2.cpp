#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct DSU {
    int length;
    vector<int> parent;
    vector<vector<int>> adj;
    int component;
    DSU(int l) {
        length = l;
        for (int i = 0; i < length; i++) {
            parent.push_back(i);
            adj.push_back({});
        }
        component = l;
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if (rooti == rootj) {
            return;
        }
        if (adj[rooti].size() > adj[rootj].size()) {
            swap(rooti, rootj);
        }
        parent[rooti] = rootj;
        component--;

        for (const int& node : adj[rooti]) {
            adj[rootj].push_back(node);
        }
        adj[rooti].clear();
    }
    int components() { return component; }
};
int main() {
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    DSU dsu = DSU(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dsu.adj[a].push_back(b);
    }
    vector<int> in_queue(N, false);
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (dsu.adj[i].size() > 1) {
            q.push(i);
            in_queue[i] = true;
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        curr = dsu.find(curr);
        in_queue[curr] = false;
        if (dsu.adj[curr].size() <= 1) {
            continue;
        }
        int admirer = dsu.adj[curr].back();
        dsu.adj[curr].pop_back();
        while (!dsu.adj[curr].empty()) {
            int other_admirer = dsu.adj[curr].back();
            dsu.adj[curr].pop_back();
            dsu.merge(admirer, other_admirer);
            admirer = dsu.find(admirer);
            curr = dsu.find(curr);
            if (dsu.adj[dsu.find(other_admirer)].size() > 1 &&
                !in_queue[dsu.find(other_admirer)]) {
                q.push(dsu.find(other_admirer));
                in_queue[dsu.find(other_admirer)] = true;
            }
        }
        dsu.adj[curr].push_back(dsu.find(admirer));
    }
    vector<int> color(N, 0);
    int curr_color = 1;
    for (int i = 0; i < N; i++) {
        int root = dsu.find(i);
        if (color[root] == 0) {
            color[root] = curr_color;
            curr_color++;
        }
        cout << color[root] << '\n';
    }
    return 0;
}