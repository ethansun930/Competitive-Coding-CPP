#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int q = 0; q < Q; q++) {
        int c, d, t, s, f;
        cin >> c >> d >> t >> s >> f;
        c--;
        d--;
        s--;
        f--;
    }
}
int main() {
    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}