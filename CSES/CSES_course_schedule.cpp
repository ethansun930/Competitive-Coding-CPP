#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> req(n);
    vector<int> edges(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        req[a].push_back(b);
        edges[b]++;
    }
    queue<int> process;
    for (int i = 0; i < n; i++) {
        if (edges[i] == 0) {
            process.push(i);
        }
    }
    int count = 0;
    vector<int> path;
    while (!process.empty()) {
        int node = process.front();
        process.pop();
        path.push_back(node);
        count++;
        for (int i : req[node]) {
            edges[i]--;
            if (edges[i] == 0) {
                process.push(i);
            }
        }
    }
    if (count != n) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << path[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}