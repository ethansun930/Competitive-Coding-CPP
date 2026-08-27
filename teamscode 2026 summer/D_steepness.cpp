#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

double ab(double n) {
    if (n >= 0) {
        return n;
    }
    return -n;
}
void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        double y = x;
        a[i] = y;
    }
    vector<vector<double>> steepness(n, vector<double>(n));
    double ans_max = 0.0;
    double ans_min = (INT_MAX) / (1.0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            steepness[i][j] = ab((a[j] - a[i]) / (j - i));
            ans_max = max(ans_max, steepness[i][j]);
            ans_min = min(ans_min, steepness[i][j]);
        }
    }
    cout << ans_max << ' ' << ans_min << '\n';
    int m;
    cin >> m;
    for (int t = 0; t < m; t++) {
        int x, z;
        cin >> x >> z;
        x--;
        double y = z;
        for (int i = 0; i < n; i++) {
            a[x] = y;
            steepness[x][i] = ab((a[x] - a[i]) / (x - i));
            steepness[i][x] = steepness[x][i];
        }
        ans_max = 0.0;
        ans_min = (INT_MAX) / 1.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans_max = max(ans_max, steepness[i][j]);
                ans_min = min(ans_min, steepness[i][j]);
            }
        }
        cout << ans_max << ' ' << ans_min << '\n';
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        solve();
    }
    return 0;
}