#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    int comp_count;
    DSU(int l) {
        comp_count = l;
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
        comp_count--;
        if (size[find(i)] <= size[find(j)]) {
            size[find(j)] += size[find(i)];
            parent[find(i)] = find(j);
        }
        else {
            size[find(i)] += size[find(j)];
            parent[find(j)] = find(i);
        }
    }
    bool finished() {
        return (comp_count == 1);
    }
};
struct Edge {
    int a, b, d;
    bool operator<(const Edge& other) const {
        return d < other.d;
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int, vector<int>> c;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (c.find(x) != c.end()) {
            c[x].push_back(i);
        }
        else {
            c[x] = {i};
        }
    }
    DSU dsu = DSU(N);
    for (pair<int, vector<int>> a : c) {
        int first = a.second[0];
        for (int i : a.second) {
            if (i == first) {
                continue;
            }
            dsu.merge(first, i);
        }
    }
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].d;
        edges[i].a--;
        edges[i].b--;
    }
    sort(edges.begin(), edges.end());
    int i = 0;
    long long ans = 0;
    while (!dsu.finished()) {
        if (dsu.find(edges[i].a) == dsu.find(edges[i].b)) {
            i++;
            continue;
        }
        ans += edges[i].d;
        dsu.merge(edges[i].a, edges[i].b);
        i++;
    }
    cout << ans << '\n';
    return 0;
}