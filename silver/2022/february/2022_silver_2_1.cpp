#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int node, vector<vector<int>>& adj,
         vector<vector<bool>>& reachable) {
    reachable[start][node] = true;
    for (const int& child : adj[node]) {
        if (!reachable[start][child]) {
            dfs(start, child, adj, reachable);
        }
    }
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<vector<int>> wishlists(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            cin >> wishlists[i][j];
            wishlists[i][j]--;
            if (!found) {
                adj[i].push_back(wishlists[i][j]);
            }
            if (wishlists[i][j] == i) {
                found = true;
            }
        }
    }
    vector<vector<bool>> reachable(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        dfs(i, i, adj, reachable);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reachable[wishlists[i][j]][i]) {
                cout << wishlists[i][j] + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}