#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int N, Q, C;
    cin >> N >> Q >> C;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    vector<pair<int, int>> pairs(Q);
    for (int i = 0; i < Q; i++) {
        cin >> pairs[i].second >> pairs[i].first;
        pairs[i].first--;
        pairs[i].second--;
    }
    sort(pairs.begin(), pairs.end());
    int curr = 0;
    int index = 0;
    for (int i = 0; i < Q; i++) {
        for (int j = index; j <= pairs[i].second; j++) {
            c[j] = max(c[j], 1);
            curr = max(c[j], curr);
        }
        index = pairs[i].second + 1;
        if (c[pairs[i].first] == 0) {
            c[pairs[i].first] = curr + 1;
        } else {
            if (c[pairs[i].first] <= curr) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int i = index; i < N; i++) {
        c[i] = max(c[i], 1);
    }
    cout << c[0];
    for (int i = 1; i < N; i++) {
        cout << ' ' << c[i];
    }
    cout << '\n';
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}