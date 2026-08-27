#include <iostream>
#include <vector>
using namespace std;

int value(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size()) {
        return 0;
    }
    return 1;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        grid[r][c] = 1 - grid[r][c];
        bool ok = false;
        for (int k = 0; k < n; k++) {
            bool curr = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (value(grid, i, j) != value(grid, i, k - j)) {
                        curr = false;
                        break;
                    }
                }
                if (!curr) {
                    break;
                }
            }
            ok = ok || curr;
            if (ok) {
                break;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}