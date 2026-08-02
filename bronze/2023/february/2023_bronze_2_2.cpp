#include <iostream>
#include <vector>
using namespace std;

void stamp(vector<vector<int>>& painting, vector<vector<int>>& stamper,
           vector<vector<int>>& curr, int i, int j) {
    int ok = true;
    for (int a = 0; a < stamper.size(); a++) {
        for (int b = 0; b < stamper.size(); b++) {
            if (painting[i + a][j + b] == 0 && stamper[a][b] == 1) {
                ok = false;
            }
        }
    }
    if (ok) {
        for (int a = 0; a < stamper.size(); a++) {
            for (int b = 0; b < stamper.size(); b++) {
                if (curr[i + a][j + b] == 0 && stamper[a][b] == 1) {
                    curr[i + a][j + b] = 1;
                }
            }
        }
    }
}
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> painting(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            if (x == '*') {
                painting[i][j] = 1;
            }
        }
    }
    int K;
    cin >> K;
    vector<vector<int>> stamp1(K, vector<int>(K, 0));
    vector<vector<int>> stamp2(K, vector<int>(K, 0));
    vector<vector<int>> stamp3(K, vector<int>(K, 0));
    vector<vector<int>> stamp4(K, vector<int>(K, 0));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            char x;
            cin >> x;
            if (x == '*') {
                stamp1[i][j] = 1;
                stamp2[j][K - i - 1] = 1;
                stamp3[K - j - 1][i] = 1;
                stamp4[K - i - 1][K - j - 1] = 1;
            }
        }
    }
    vector<vector<int>> curr(N, vector<int>(N, 0));
    for (int i = 0; i < N - K + 1; i++) {
        for (int j = 0; j < N - K + 1; j++) {
            stamp(painting, stamp1, curr, i, j);
            stamp(painting, stamp2, curr, i, j);
            stamp(painting, stamp3, curr, i, j);
            stamp(painting, stamp4, curr, i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (curr[i][j] != painting[i][j]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}