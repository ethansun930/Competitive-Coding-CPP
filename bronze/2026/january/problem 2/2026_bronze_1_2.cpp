#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    vector<array<int, 4>> unique_moves;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int z = 0; z < N; z++) {
                if (move_counts[x][y][z] > 0) {
                    unique_moves.push_back({{x, y, z, move_counts[x][y][z]}});
                }
            }
        }
    }
    int ans = 0;
    int works = 0;
    for (int i = 0; i < (1 << N); i++) {
        int curr = 0;
        for (const auto& j : unique_moves) {
            int x = j[0];
            int y = j[1];
            int z = j[2];
            if (((i & (1 << x)) == 0) && ((i & (1 << y)) != 0) &&
                ((i & (1 << z)) != 0)) {
                curr += move_counts[x][y][z];
            }
        }
        if (curr == ans) {
            works++;
        } else if (curr > ans) {
            ans = curr;
            works = 1;
        }
    }
    cout << ans << ' ' << works << '\n';
    return 0;
}