#include<iostream>
#include<vector>
using namespace std;

struct Quer {
    int t, x, y;
}
struct DSU {
    vector<int> parent;
    
}
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<Quer> queries(Q);
    for (int q = 0; q < Q; q++) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        if (t == 'C') {
            queries.push_back({0, x, y});
        }
        else if (t == 'A') {
            queries.push_back({1, x, y});
        }
        else {
            queries.push_back({2, x, y});
        }
    }
}