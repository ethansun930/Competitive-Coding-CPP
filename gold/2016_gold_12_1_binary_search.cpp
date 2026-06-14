#include <cstdio>
#include <iostream>
#include <utility>
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
bool works(long long power, vector<pair<int, int>>& coordinates) {
    DSU dsu = DSU(coordinates.size());
    for (int i = 0; i < coordinates.size(); i++) {
        int xi = coordinates[i].first;
        int yi = coordinates[i].second;
        for (int j = i + 1; j < coordinates.size(); j++) {
            int xj = coordinates[j].first;
            int yj = coordinates[j].second;
            if (((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)) <= power) {
                dsu.merge(i, j);
            }
        }
    }
    return dsu.complete();
}
int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> coordinates(N);
    for (int i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    long long left = 0;
    long long right = 1 << 30;
    while (left < right) {
        long long middle = (left + right) / 2;
        if (works(middle, coordinates)) {
            right = middle;
            // cout << "left, right, middle, right was changed" << left << ' '
            // << right << ' ' << middle << '\n';
        } else {
            left = middle + 1;
            // cout << "left, right, middle, left was changed" << left << ' ' <<
            // right << ' ' << middle << '\n';
        }
    }
    cout << right << '\n';
    return 0;
}