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
    for (int i = 0; i < N; i++) {
        if (i == 0 || f[i] != f[i - 1]) {
            tube[0].push_back(f[i] - '0');
        }
        if (i == 0 || s[i] != s[i - 1]) {
            tube[1].push_back(s[i] - '0');
        }
    }
    if (P == 1) {
        int ans = tube[0].size() + tube[1].size() - 2;
        if (tube[0][0] == tube[1][0]) {
            ans++;
        }
        if (ans > 1) {
            ans++;
        }
        cout << ans << '\n';
        return;
    }
    vector<pair<int, int>> moves;
    while (tube[0].size() > 1 && tube[1].size() > 1) {
        if (tube[0].back() == tube[1].back()) {
            if (tube[0].size() >= tube[1].size()) {
                tube[0].pop_back();
                moves.push_back({1, 2});
            } else {
                tube[1].pop_back();
                moves.push_back({2, 1});
            }
        } else {
            if (tube[2].empty()) {
                if (tube[0].size() >= tube[1].size()) {
                    tube[2].push_back(tube[0].back());
                    tube[0].pop_back();
                    moves.push_back({1, 3});
                } else {
                    tube[2].push_back(tube[1].back());
                    tube[1].pop_back();
                    moves.push_back({2, 3});
                }
            } else {
                if (tube[0].back() == tube[2].back()) {
                    tube[0].pop_back();
                    moves.push_back({1, 3});
                } else {
                    tube[1].pop_back();
                    moves.push_back({2, 3});
                }
            }
        }
    }
    if (tube[0].size() == 1 && !tube[2].empty()) {
        if (tube[0][0] == tube[2].back()) {
            moves.push_back({3, 1});
            tube[2].pop_back();
        }
    }
    if (tube[1].size() == 1 && !tube[2].empty()) {
        if (tube[1][0] == tube[2].back()) {
            moves.push_back({3, 2});
            tube[2].pop_back();
        }
    }
    while (tube[1].size() > 1) {
        if (tube[1].back() == tube[0].back()) {
            moves.push_back({2, 1});
            tube[1].pop_back();
        } else {
            moves.push_back({2, 3});
            if (tube[2].empty()) {
                tube[2].push_back(tube[1].back());
            }
            tube[1].pop_back();
        }
    }
    while (tube[0].size() > 1) {
        if (tube[1].back() == tube[0].back()) {
            moves.push_back({1, 2});
            tube[0].pop_back();
        } else {
            moves.push_back({1, 3});
            if (tube[2].empty()) {
                tube[2].push_back(tube[0].back());
            }
            tube[0].pop_back();
        }
    }
    if (!tube[2].empty()) {
        if (tube[0][0] == tube[1][0]) {
            moves.push_back({1, 2});
            moves.push_back({3, 1});
        } else {
            if (tube[2][0] == tube[0][0]) {
                moves.push_back({3, 1});
            } else {
                moves.push_back({3, 2});
            }
        }
    }
    cout << moves.size() << '\n';
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i].first << ' ' << moves[i].second << '\n';
    }
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
/*
1:
2: 12
3:1
*/