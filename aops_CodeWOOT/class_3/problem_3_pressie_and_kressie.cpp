#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#include<climits>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    int max_size = 1;
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
            max_size = max(max_size, size[find(j)]);
            parent[find(i)] = find(j);
        }
        else {
            size[find(i)] += size[find(j)];
            max_size = max(max_size, size[find(i)]);
            parent[find(j)] = find(i);
        }
    }
};
int main() {
    int N, M;
    char X, Y;
    cin >> N >> M >> X >> Y;
    if (X == 'P' && Y == 'S') {
        for (int i = 2; i <= N; i++) {
            cout << i << '\n';
        }
    }
    else if (X == 'K' && Y == 'W') {
        DSU dsu = DSU(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (dsu.find(a) != dsu.find(b)) {
                cout << i + 1 << '\n';
                dsu.merge(a, b);
            }
        }
    }
    else if (X == 'K' && Y == 'S') {
        DSU dsu = DSU(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (dsu.find(a) != dsu.find(b)) {
                dsu.merge(a, b);
                cout << dsu.max_size << '\n';
            }
        }
    }
    else {
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        vector<int> visited(N, INT_MAX);
        vector<int> b_visited(N, false);
        visited[0] = 1;
        priority_queue<pair<int, int>> pq;
        pq.push({-1, 0});
        while (!pq.empty()) {
            pair<int, int> val = pq.top();
            pq.pop();
            int node = val.second;
            int dis = -val.first;
            if (visited[node] < dis || b_visited[node]) {
                continue;
            }
            b_visited[node] = true;
            if (node != 0) {
                cout << dis << '\n';
            }
            for (pair<int, int> e : adj[node]) {
                if (visited[e.first] <= e.second || b_visited[e.first]) {
                    continue;
                }
                pq.push({-e.second, e.first});
            }
        }
    }
    return 0;
}