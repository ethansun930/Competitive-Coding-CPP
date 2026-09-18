#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N + 26);
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        bool contain[26] = {false};
        for (int j = 0; j < name.size(); j++) {
            contain[name[j] - 'A'] = true;
        }
        for (int j = 0; j < 26; j++) {
            if (contain[j]) {
                adj[j].push_back(i + 26);
                adj[i + 26].push_back(j);
            }
        }
    }
    vector<vector<int>> d(26, vector<int>(26, INT_MAX));
    for (int i = 0; i < 26; i++) {
        queue<pair<int, int>> q;
        q.push({i, 0});
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            if (node.first < 26 && d[i][node.first] <= node.second / 2) {
                continue;
            }
            if (node.first < 26) {
                d[i][node.first] = node.second / 2;
            }
            for (const int& j : adj[node.first]) {
                q.push({j, node.second + 1});
            }
        }
    }
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = INT_MAX;
        for (const int& i : adj[a + 26]) {
            for (const int& j : adj[b + 26]) {
                if (d[i][j] != INT_MAX) {
                    ans = min(ans, d[i][j] + 1);
                }
            }
        }
        if (ans == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}