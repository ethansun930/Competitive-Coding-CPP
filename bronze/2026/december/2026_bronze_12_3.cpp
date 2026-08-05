// https://usaco.org/index.php?page=viewproblem2&cpid=1541
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int Q;
    cin >> Q;
    vector<vector<long long>> photo_sums(N, vector<long long>(N, 0));
    vector<vector<long long>> beauties(N, vector<long long>(N, 0));
    long long ans = 0;
    while (Q--) {
        int r, c;
        long long v;
        cin >> r >> c >> v;
        r--;
        c--;
        for (int i = max(K - 1, r); i < min(N, r + K); i++) {
            for (int j = max(K - 1, c); j < min(N, c + K); j++) {
                photo_sums[i][j] += v - beauties[r][c];
                ans = max(ans, photo_sums[i][j]);
            }
        }
        beauties[r][c] = v;
        cout << ans << '\n';
    }
    return 0;
}
