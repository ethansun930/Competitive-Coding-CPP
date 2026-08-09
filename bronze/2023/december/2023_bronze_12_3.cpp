#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long floor(long long a, long long b) {
    long long res = a / b;
    long long rem = a % b;
    if (rem != 0 && ((a * b) < 0)) {
        res--;
    }
    return res;
}
void solve() {
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        t[x] = i;
    }
    long long ans = 0;
    long long right = LLONG_MAX;
    for (int i = 0; i < N - 1; i++) {
        if (a[t[i + 1]] == a[t[i]]) {
            if (h[t[i]] <= h[t[i + 1]]) {
                cout << -1 << '\n';
                return;
            }
            continue;
        }
        if (a[t[i + 1]] > a[t[i]]) {
            right =
                min(right,
                    -floor(h[t[i + 1]] - h[t[i]], a[t[i + 1]] - a[t[i]]) - 1);
            if (ans > right) {
                cout << -1 << '\n';
                return;
            }
        } else {
            ans = max(ans,
                      floor(h[t[i]] - h[t[i + 1]], a[t[i + 1]] - a[t[i]]) + 1);
        }
    }
    if (ans <= right) {
        cout << ans << '\n';
        return;
    }
    cout << -1 << '\n';
}
/*
x days.
h[t[n]] + x * a[t[n]] > h[t[n + 1]] + x * a[t[n + 1]]
x * (a[t[n + 1]] - a[t[n]]) < h[t[n]] - h[t[n + 1]]
3 + 10x > 6 + 8x
x * (-2) < -3
x > 3/2

*/

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
