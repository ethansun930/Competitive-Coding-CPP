// my TLE solution for before the finalize and view solution
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

long long mod_pow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    long long recur = mod_pow(x, y/2);
    if (y % 2 == 0) {
        return ((recur * recur)%1000000007);
    }
    return ((((recur * recur)%1000000007) * x)%1000000007);
}
int colors(vector<unordered_set<int>>& adj, vector<int>& power) {
    int N = adj.size();
    for (int i = 0; i < N; i++) {
        if (adj[i].empty()) {
            continue;
        }
        int j = *adj[i].begin();
        adj[i].erase(j);
        adj[j].erase(i);
        int curr = colors(adj, power);
        adj[i].insert(j);
        adj[j].insert(i);
        vector<unordered_set<int>> new_adj(N - 1);
        for (int k = 0; k < j; k++) {
            for (int l : adj[k]) {
                if (l > j) {
                    new_adj[k].insert(l - 1);
                }
                else if (l < j) {
                    new_adj[k].insert(l);
                }
            }
        }
        for (int k = j; k < N - 1; k++) {
            for (int l : adj[k + 1]) {
                if (l > j) {
                    new_adj[k].insert(l - 1);
                }
                else if (l < j) {
                    new_adj[k].insert(l);
                }
            }
        }
        for (int k : adj[j]) {
            if (k == i) {
                continue;
            }
            if (k < j) {
                new_adj[i].insert(k);
            }
            else {
                new_adj[i].insert(k - 1);
            }
        }
        return ((curr - colors(new_adj, power) + 1000000007)%1000000007);
    }
    return power[N];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, C;
    cin >> N >> M >> C;
    vector<unordered_set<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> power(N + 1);
    for (int i = 0; i <= N; i++) {
        power[i] = (int)mod_pow(C, i);
    }
    cout << colors(adj, power) << '\n';
    return 0;
}