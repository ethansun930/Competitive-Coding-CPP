#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void dfs(int tile, int boot, int N, int B, vector<int>& f,
         vector<pair<int, int>>& boots, vector<vector<bool>>& visited,
         int& ans) {
    if (tile == N - 1) {
        ans = min(ans, boot);
        return;
    }
    if (visited[tile][boot]) {
        return;
    }
    visited[tile][boot] = true;
    for (int i = tile + 1; i <= min(N - 1, tile + boots[boot].second); i++) {
        if (boots[boot].first >= f[i]) {
            dfs(i, boot, N, B, f, boots, visited, ans);
        }
    }
    for (int next_boot = boot + 1; next_boot < boots.size(); next_boot++) {
        if (boots[next_boot].first >= f[tile]) {
            dfs(tile, next_boot, N, B, f, boots, visited, ans);
        }
    }
    return;
}
int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int N, B;
    cin >> N >> B;
    vector<int> f(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> f[i];
    }
    vector<pair<int, int>> boots(B, make_pair(0, 0));
    for (int i = 0; i < B; i++) {
        cin >> boots[i].first >> boots[i].second;
    }
    vector<vector<bool>> visited(N, vector<bool>(B, false));
    int ans = B;
    dfs(0, 0, N, B, f, boots, visited, ans);
    cout << ans << '\n';
    return 0;
}