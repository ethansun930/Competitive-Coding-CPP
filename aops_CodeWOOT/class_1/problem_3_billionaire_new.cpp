#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Edge {
    int a, b;
    long long d;
};
void solve() {
    int S, N;
    long long X;
    cin >> S >> N >> X;
    vector<Edge> adj(S);
    for (int i = 0; i < S; i++) {
        cin >> adj[i].a >> adj[i].b >> adj[i].d;
        adj[i].a--;
        adj[i].b--;
    }
    vector<long long> d(N, LLONG_MIN);
    d[0] = 1000000;
    for (int k = 0; k < N - 1; k++) {
        for (int i = 0; i < S; i++) {
            if (d[adj[i].a] == LLONG_MIN) {
                continue;
            }
            if (d[adj[i].a] < adj[i].d) {
                continue;
            }
            d[adj[i].b] = max(d[adj[i].b], d[adj[i].a] - adj[i].d);
            if (d[adj[i].b] >= X) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < S; i++) {
        if (d[adj[i].a] == LLONG_MIN) {
            continue;
        }
        if (d[adj[i].a] < adj[i].d) {
            continue;
        }
        if (d[adj[i].a] - adj[i].d > d[adj[i].b]) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}