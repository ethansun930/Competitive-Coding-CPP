#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    queue<pair<long long, long long>> q;
    q.push(make_pair(a, 0));
    unordered_set<long long> visited;
    visited.insert(a);
    while (!q.empty()) {
        pair<long long, long long> node = q.front();
        q.pop();
        if (node.first == b) {
            cout << node.second << '\n';
            return;
        }
        if (node.first % 2 == 0) {
            long long new_node = node.first / 2;
            if (visited.find(new_node) == visited.end()) {
                q.push(make_pair(new_node, node.second + 1));
                visited.insert(new_node);
            }
        }
        if (node.first < b) {
            long long new_node = 2 * node.first;
            if (visited.find(new_node) == visited.end()) {
                q.push(make_pair(new_node, node.second + 1));
                visited.insert(new_node);
            }
        }
        if (node.first < (2 * b) || node.first % 2 == 1) {
            long long new_node = node.first + 1;
            if (visited.find(new_node) == visited.end()) {
                q.push(make_pair(new_node, node.second + 1));
                visited.insert(new_node);
            }
        }
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }
    return 0;
}