#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> h(N);
    set<int> possible;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        h[i]--;
    }
    if (N == 2) {
        if (h[0] == h[1]) {
            cout << h[0] + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    for (int j = 0; j <= (N - 3); j++) {
        int type = -1;
        if (h[j] == h[j + 1] || h[j] == h[j + 2]) {
            type = h[j];
        } else if (h[j + 1] == h[j + 2]) {
            type = h[j + 1];
            j++;
        }
        if (type != -1) {
            possible.insert(type + 1);
        }
    }
    if (possible.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    int x = *possible.begin();
    cout << x;
    possible.erase(x);
    for (const int& i : possible) {
        cout << ' ' << i;
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