#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct DSU {
    long long length;
    vector<long long> parent;
    DSU(int l) {
        length = l;
        for (long long i = 0; i < length; i++) {
            parent.push_back(i);
        }
    }
    long long find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int i, int j) {
        long long rooti = find(i);
        long long rootj = find(j);
        if (rooti != rootj) {
            parent[rooti] = rootj;
        }
    }
    bool complete() {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (parent[i] == i) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
long long distance(pair<long long, long long> i, pair<long long, long long> j) {
    return ((i.first - j.first) * (i.first - j.first) +
            (i.second - j.second) * (i.second - j.second));
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    long long N;
    cin >> N;
    vector<pair<long long, long long>> coordinates(N);
    for (long long i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    priority_queue<vector<long long>, vector<vector<long long>>,
                   greater<vector<long long>>>
        edges;
    for (long long i = 0; i < N; i++) {
        pair<long long, long long> I = coordinates[i];
        for (long long j = i + 1; j < N; j++) {
            pair<long long, long long> J = coordinates[j];
            edges.push({distance(I, J), i, j});
        }
    }
    DSU dsu = DSU(N);
    while (!edges.empty()) {
        vector<long long> edge = edges.top();
        edges.pop();
        dsu.merge(edge[1], edge[2]);
        if (dsu.complete()) {
            cout << edge[0] << '\n';
            break;
        }
    }
    return 0;
}