#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Cow {
    int x, y, xr, yr;
};
long long get_prefix_sum(vector<vector<long long>>& prefix_sums, int l, int u,
                         int r, int d) {
    if (l > r || u > d) return 0;
    return prefix_sums[r][d] - prefix_sums[l - 1][d] - prefix_sums[r][u - 1] +
           prefix_sums[l - 1][u - 1];
}
int main() {
    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cows[i].x = x;
        cows[i].y = y;
    }
    sort(cows.begin(), cows.end(),
         [](const Cow& a, const Cow& b) { return a.x < b.x; });
    for (int i = 0; i < N; i++) {
        cows[i].xr = i + 1;
    }
    sort(cows.begin(), cows.end(),
         [](const Cow& a, const Cow& b) { return a.y < b.y; });
    for (int i = 0; i < N; i++) {
        cows[i].yr = i + 1;
    }
    vector<vector<long long>> grid(N + 1, vector<long long>(N + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        grid[cows[i].xr][cows[i].yr] = 1;
    }
    vector<vector<long long>> prefix_sums(N + 1, vector<long long>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix_sums[i][j] = grid[i][j] + prefix_sums[i - 1][j] +
                                prefix_sums[i][j - 1] -
                                prefix_sums[i - 1][j - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Cow I = cows[i];
            Cow J = cows[j];
            int l = min(I.xr, J.xr);
            int r = max(I.xr, J.xr);
            int u = min(I.yr, J.yr);
            int d = max(I.yr, J.yr);
            long long top_choices = get_prefix_sum(prefix_sums, l, 1, r, u);
            long long bottom_choices = get_prefix_sum(prefix_sums, l, d, r, N);
            ans += (top_choices * bottom_choices);
        }
    }
    ans += N + 1;
    cout << ans << '\n';
    return 0;
}