#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<long long>> d(N, vector<long long>(N, LLONG_MAX));
    for (int i = 0; i < N; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = min(d[a][b], c);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (d[i][k] == LLONG_MAX) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (d[k][j] == LLONG_MAX) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += d[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}