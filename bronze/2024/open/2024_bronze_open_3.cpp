#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> h(N - 1);
    vector<bool> contains(N, false);
    bool double1 = false;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        h[i]--;
        if (contains[h[i]]) {
            if (h[i] != 0) {
                cout << -1 << '\n';
                return;
            } else {
                double1 = true;
            }
        }
        contains[h[i]] = true;
    }
    if (!contains[0]) {
        cout << -1 << '\n';
        return;
    }
    if (h[N - 2] != 0) {
        cout << -1 << '\n';
        return;
    }
    if (!double1) {
        cout << 1;
        for (int i = N - 3; i >= 0; i--) {
            cout << ' ' << h[i] + 1;
        }
        for (int i = 1; i < N; i++) {
            if (!contains[i]) {
                cout << i + 1 << '\n';
                return;
            }
        }
        return;
    }
    vector<int> ans(N, -1);
    for (int i = 1; i < N; i++) {
        if (!contains[i]) {
            if (ans[0] == -1) {
                ans[0] = i;
            } else {
                ans[N - 1] = i;
                break;
            }
        }
    }
    int l = 1;
    int r = N - 2;
    for (int i = 0; i < N - 1; i++) {
        if (ans[l] > ans[r]) {
            ans[l + 1] = h[i];
            l++;
        } else {
            ans[r - 1] = h[i];
            r--;
        }
    }
    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << ' ' << ans[i];
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}