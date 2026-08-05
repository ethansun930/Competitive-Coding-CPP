#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (N % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    bool ok = true;
    for (int i = 0; i < S.size() / 2; i++) {
        if (S[i] != S[i + S.size() / 2]) {
            ok = false;
        }
    }
    if (ok) {
        cout << 1 << '\n';
        for (int i = 0; i < S.size() - 1; i++) {
            cout << 1 << ' ';
        }
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
    vector<int> ans(S.size(), 1);
    for (int i = 0; i < S.size() / 2; i += 3) {
        if (S[i] == S[i + S.size() / 2 + 1]) {
            ans[i + 2] = 2;
            ans[i + S.size() / 2] = 2;
        } else if (S[i + 1] == S[i + S.size() / 2]) {
            ans[i] = 2;
            ans[i + S.size() / 2 + 2] = 2;
        }
    }
    for (int i = 0; i < S.size() - 1; i++) {
        cout << ans[i] << ' ';
    }
    cout << ans[S.size() - 1] << '\n';
}
int main() {
    int T, k;
    cin >> T >> k;
    while (T--) {
        solve();
    }
    return 0;
}