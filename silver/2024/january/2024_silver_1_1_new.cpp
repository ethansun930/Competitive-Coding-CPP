#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int N, Q, C;
    cin >> N >> Q >> C;
    vector<int> c(N);
    vector<bool> change(N, false);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        if (c[i] == 0) {
            change[i] = true;
        }
    }
    vector<pair<int, int>> pairs(Q);
    for (int i = 0; i < Q; i++) {
        cin >> pairs[i].second >> pairs[i].first;
        pairs[i].first--;
        pairs[i].second--;
    }
    sort(pairs.begin(), pairs.end());
    vector<int> p(N, 1);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            p[i] = max(1, c[i]);
            continue;
        }
        p[i] = max(p[i - 1], c[i]);
    }
    for (int i = 0; i < Q; i++) {
        int h = pairs[i].first;
        int a = pairs[i].second;
        if (p[a] != p[h - 1]) {
            int changed = -1;
            for (int j = a; j >= 0; j--) {
                if (change[j]) {
                    c[j] = p[h - 1];
                    changed = j;
                    break;
                }
            }
            if (changed == -1) {
                cout << -1 << '\n';
                return;
            }
            for (int j = changed; j < N; j++) {
                if (p[j] >= c[changed]) {
                    break;
                }
                p[j] = c[changed];
            }
            i = -1;
        }
        if (c[h] == 0) {
            c[h] = p[a] + 1;
            if (c[h] > C) {
                cout << -1 << '\n';
                return;
            }
            for (int j = h; j < N; j++) {
                if (p[j] >= c[h]) {
                    break;
                }
                p[j] = c[h];
            }
        } else {
            if (c[h] <= p[h - 1]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << max(1, c[0]);
    for (int i = 1; i < N; i++) {
        cout << ' ' << max(1, c[i]);
    }
    cout << '\n';
    return;
}
/*
p[i] = max(c[1], c[2], ..., c[i]);
p[a[i]] = p[h[i] - 1] < p[h[i]].
*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}