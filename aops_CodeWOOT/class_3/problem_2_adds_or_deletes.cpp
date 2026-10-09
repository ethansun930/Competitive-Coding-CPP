#include<iostream>
#include<vector>
#include<unordered_set>
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
struct Quer {
    char t;
    int x, y;
};
int main() {
    int N, M, D, Q;
    cin >> N >> M >> D >> Q;
    if (D == 0) {
        DSU dsu = DSU(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            dsu.merge(a, b);
        }
        for (int i = 0; i < Q; i++) {
            char t;
            int x, y;
            cin >> t >> x >> y;
            x--;
            y--;
            if (t == 'C') {
                if (dsu.find(x) == dsu.find(y)) {
                    cout << "YES" << '\n';
                }
                else {
                    cout << "NO" << '\n';
                }
            }
            else {
                dsu.merge(x, y);
            }
        }
    }
    else {
        vector<unordered_set<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].insert(b);
        }
        vector<Quer> queries;
        for (int i = 0; i < Q; i++) {
            char t;
            int x, y;
            cin >> t >> x >> y;
            x--;
            y--;
            if (t == 'C') {
                queries.push_back({t, x, y});
                continue;
            }
            if (adj[x].find(y) != adj[x].end()) {
                adj[x].erase(y);
                queries.push_back({t, x, y});
            }
        }
        DSU dsu = DSU(N);
        for (int i = 0; i < N; i++) {
            for (int j : adj[i]) {
                dsu.merge(i, j);
            }
        }
        vector<bool> answers;
        for (int q = queries.size() - 1; q >= 0; q--) {
            char t = queries[q].t;
            int x = queries[q].x;
            int y = queries[q].y;
            if (t == 'C') {
                if (dsu.find(x) == dsu.find(y)) {
                    answers.push_back(true);
                }
                else {
                    answers.push_back(false);
                }
                continue;
            }
            dsu.merge(x, y);
        }
        for (int i = answers.size() - 1; i >= 0; i--) {
            if (answers[i]) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}