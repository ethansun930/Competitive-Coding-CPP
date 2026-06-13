#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> d(n, vector<long long>(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (d[a][b] == -1 || c < d[a][b]) {
            d[a][b] = c;
            d[b][a] = c;
        }
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] != -1 && d[k][j] != -1 &&
                    (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j])) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    vector<long long> answers(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        answers[i] = d[x][y];
    }
    for (int i = 0; i < q; i++) {
        cout << answers[i] << '\n';
    }
    return 0;
}