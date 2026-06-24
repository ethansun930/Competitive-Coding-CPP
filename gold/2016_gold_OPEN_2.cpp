#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct DSU {
    int length;
    vector<int> parent;
    int component;
    DSU(int l) {
        length = l;
        for (int i = 0; i < length; i++) {
            parent.push_back(i);
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
        if (rooti != rootj) {
            parent[rooti] = rootj;
            component--;
        }
    }
    int components() { return component; }
};
int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> closing(N);
    for (int i = 0; i < N; i++) {
        cin >> closing[i];
        closing[i]--;
    }
    DSU dsu = DSU(N);
    vector<bool> answers;
    unordered_set<int> visited;
    for (int i = N - 1; i >= 0; i--) {
        for (const int& j : adj[closing[i]]) {
            if (visited.find(j) != visited.end()) {
                dsu.merge(closing[i], j);
                // cout << "merged: " << closing[i] << ' ' << j << '\n';
            }
        }
        if (dsu.components() <= (i + 1)) {
            answers.push_back(true);
            // cout << "component count: " << closing[i] << ' ' <<
            // dsu.components()
            //      << " worked" << '\n';
        } else {
            answers.push_back(false);
            // cout << "component count: " << closing[i] << ' ' <<
            // dsu.components()
            //      << " failed" << '\n';
        }
        visited.insert(closing[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        if (answers[i] == true) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}