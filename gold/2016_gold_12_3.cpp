#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int N, xl, yl, xb, yb;
    cin >> N >> xl >> yl >> xb >> yb;
    unordered_map<int, vector<int>> xtoy;
    unordered_map<int, vector<int>> ytox;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        xtoy[x].push_back(y);
        ytox[y].push_back(x);
    }
    queue<vector<int>> q;
    unordered_set<int> visitedx;
    unordered_set<int> visitedy;
    q.push({xl, 0, 0});
    q.push({yl, 1, 0});
    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        if (node[1] == 0) {
            if (node[0] == xb) {
                cout << node[2] << '\n';
                return 0;
            }
            if (visitedx.find(node[0]) != visitedx.end()) {
                continue;
            }
            visitedx.insert(node[0]);
            for (const int& y : xtoy[node[0]]) {
                q.push({y, 1, node[2] + 1});
            }
        } else {
            if (node[0] == yb) {
                cout << node[2] << '\n';
                return 0;
            }
            if (visitedy.find(node[0]) != visitedy.end()) {
                continue;
            }
            visitedy.insert(node[0]);
            for (const int& x : ytox[node[0]]) {
                q.push({x, 0, node[2] + 1});
            }
        }
    }
    return 0;
}