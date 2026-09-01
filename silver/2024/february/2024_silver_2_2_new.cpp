// looked at proper greedy method, because the previous greedy method wasn't
// perfectly optimized to the minimum number of moves.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int N, P;
    cin >> N >> P;
    string f, s;
    cin >> f >> s;
    vector<int> tube[3];
    if (f[0] == s[0]) {
        tube[0].push_back(3 - (s[0] - '0'));
    }
    for (int i = 0; i < N; i++) {
        if (i == 0 || f[i] != f[i - 1]) {
            tube[0].push_back(f[i] - '0');
        }
        if (i == 0 || s[i] != s[i - 1]) {
            tube[1].push_back(s[i] - '0');
        }
    }
    int ans = tube[0].size() + tube[1].size() - 2;
    if (ans > 1) {
        ans++;
    }
    cout << ans << '\n';
    if (P == 1) {
        return;
    }
    vector<pair<int, int>> moves;
    if (tube[0].back() == tube[1].back()) {
        if (tube[0].size() > 1) {
            tube[0].pop_back();
            cout << "1 2" << '\n';
        } else {
            tube[1].pop_back();
            cout << "2 1" << '\n';
        }
    }
    if (tube[0].size() == 1 && tube[1].size() == 1) {
        return;
    }
    if (tube[0].back() != tube[1].back()) {
        if (tube[0].size() > 1) {
            tube[2].push_back(tube[0].back());
            tube[0].pop_back();
            cout << "1 3" << '\n';
        } else {
            tube[2].push_back(tube[1].back());
            tube[1].pop_back();
            cout << "2 3" << '\n';
        }
    }
    if (tube[1][0] == tube[2][0]) {
        while (tube[0].size() > 1) {
            if (tube[1].back() == tube[0].back()) {
                cout << "1 2" << '\n';
            } else {
                cout << "1 3" << '\n';
            }
            tube[0].pop_back();
        }
        while (tube[1].size() > 1) {
            if (tube[1].back() == tube[0].back()) {
                cout << "2 1" << '\n';
            } else {
                cout << "2 3" << '\n';
            }
            tube[1].pop_back();
        }
    } else {
        while (tube[1].size() > 1) {
            if (tube[1].back() == tube[0].back()) {
                cout << "2 1" << '\n';
            } else {
                cout << "2 3" << '\n';
            }
            tube[1].pop_back();
        }
        while (tube[0].size() > 1) {
            if (tube[1].back() == tube[0].back()) {
                cout << "1 2" << '\n';
            } else {
                cout << "1 3" << '\n';
            }
            tube[0].pop_back();
        }
    }
    if (tube[0][0] == tube[2][0]) {
        cout << "3 1" << '\n';
    } else {
        cout << "3 2" << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}