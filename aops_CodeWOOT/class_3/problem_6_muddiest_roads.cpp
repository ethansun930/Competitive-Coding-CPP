#include<iostream>
#include<vector>
#include<utility>
#include<queue>
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
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> F(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> F[i];
        F[i]--;
    }
    DSU dsu = DSU(N);
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dsu.find(a) == dsu.find(b)) {
            continue;
        }
        dsu.merge(a, b);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for (int i = 0; i < N - 1; i++) {
        queue<pair<int, int>> q;
        q.push({i, 0});
        vector<bool> visited(N, false);
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            if (visited[node.first]) {
                continue;
            }
            visited[node.first] = true;
            if (node.first == F[i]) {
                cout << node.second << '\n';
                break;
            }
            
            for (pair<int, int> e : adj[node.first]) {
                if (visited[e.first]) {
                    continue;
                }
                q.push({e.first, max(e.second, node.second)});
            }
        }
    }
    return 0;
}