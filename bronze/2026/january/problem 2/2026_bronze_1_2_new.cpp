#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<vector<int>>> move_counts(
        N, vector<vector<int>>(N, vector<int>(N, 0)));
    for (int i = 0; i < K; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        move_counts[x][y][z]++;
    }
    vector<int> scores(1 << N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (move_counts[i][j][k] == 0) {
                    continue;
                }
                int M = (1 << i);
                int O = (1 << j) | (1 << k);
                for (int board = O; board < (1 << N); board = (board + 1) | O) {
                    if ((board & M) == 0) {
                        scores[board] += move_counts[i][j][k];
                    }
                }
            }
        }
    }
    int ans = 0;
    int count = 0;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > ans) {
            count = 1;
            ans = scores[i];
        } else if (scores[i] == ans) {
            count++;
        }
    }
    cout << ans << ' ' << count << '\n';
}