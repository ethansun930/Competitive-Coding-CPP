#include<iostream>
#include<vector>
using namespace std;

struct DSU {
    int l;
    vector<int> parent;
    vector<int> size;
    DSU(int length) {
        l = length;
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
        if (size[find(i)] >= size[find(j)]) {
            size[find(i)] += size[find(j)];
            parent[find(j)] = find(i);
        }
        else {
            size[find(j)] += size[find(i)];
            parent[find(i)] = find(j);
        }
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    DSU dsu = DSU(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dsu.find(a) == dsu.find(b)) {
            cout << a + 1 << ' ' << b + 1 << '\n';
            continue;
        }
        dsu.merge(a, b);
    }
    return 0;
}