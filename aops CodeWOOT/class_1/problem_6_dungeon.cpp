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
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            d[i][i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        for (int j = max(a, b); j < N; j++) {
            d[a][b][j] = w;
            d[b][a][j] = w;
        }
    }
    for (int l = 0; l < N; l++) {
        for (int k = 0; k <= l; k++) {
            for (int i = 0; i <= l; i++) {
                if (d[i][k][l] == INT_MAX) {
                    continue;
                }
            }
        }
    }
}