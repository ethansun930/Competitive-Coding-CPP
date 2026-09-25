#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<vector<int>>> d(
        N, vector<vector<int>>(N, vector<int>(N, INT_MAX)));
    vector<vector<int>> curr(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            d[i][i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        curr[a][b] = w;
        curr[b][a] = w;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (curr[i][k] == INT_MAX) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (curr[k][j] != INT_MAX) {
                    curr[i][j] = min(curr[i][j], curr[i][k] + curr[k][j]);
                }
            }
        }
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                d[i][j][k] = curr[i][j];
            }
        }
    }
    for (int q = 0; q < Q; q++) {
        int L, s, D, f;
        cin >> L >> s >> D >> f;
        L--;
        s--;
        f--;
        int ans = INT_MAX;
        for (int l = max(L, f); l < N; l++) {
            if (d[s][f][l] != INT_MAX) {
                ans = min(ans, d[s][f][l] + (l - L) * D);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}