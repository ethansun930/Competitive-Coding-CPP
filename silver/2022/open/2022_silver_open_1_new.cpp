#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    int length;
    vector<int> parent;
    DSU(int l) {
        length = l;
        for (int i = 0; i < length; i++) {
            parent.push_back(i);
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
        int rooti = find(i);
        int rootj = find(j);
        if (rooti == rootj) {
            return;
        }
        parent[rooti] = rootj;
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<pair<long long, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> v[i].first;
        v[i].second = i;
        a[i]--;
    }
    sort(v.begin(), v.end());
    DSU dsu = DSU(N);
    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (dsu.find(v[i].second) != dsu.find(a[v[i].second])) {
            dsu.merge(v[i].second, a[v[i].second]);
            ans += v[i].first;
        }
    }
    cout << ans << '\n';
    return 0;
}