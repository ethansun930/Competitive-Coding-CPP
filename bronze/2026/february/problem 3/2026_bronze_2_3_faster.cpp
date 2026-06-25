// this code was written by chatgpt, f
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int N, M;
string t;
vector<string> s;

set<int> topPos[26];               // positions in row 0
set<pair<int, int>> belowPos[26];  // positions in rows 1..N-1

vector<array<int, 4>> ans;

void removeCell(int r, int c) {
    int ch = s[r][c] - 'a';

    if (r == 0) {
        topPos[ch].erase(c);
    } else {
        belowPos[ch].erase({r, c});
    }
}

void addCell(int r, int c) {
    int ch = s[r][c] - 'a';

    if (r == 0) {
        topPos[ch].insert(c);
    } else {
        belowPos[ch].insert({r, c});
    }
}

void swapCells(int r1, int c1, int r2, int c2) {
    removeCell(r1, c1);
    removeCell(r2, c2);

    swap(s[r1][c1], s[r2][c2]);

    addCell(r1, c1);
    addCell(r2, c2);
}

void solve() {
    cin >> N >> M;
    cin >> t;

    s.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    ans.clear();

    for (int ch = 0; ch < 26; ch++) {
        topPos[ch].clear();
        belowPos[ch].clear();
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int ch = s[r][c] - 'a';

            if (r == 0) {
                topPos[ch].insert(c);
            } else {
                belowPos[ch].insert({r, c});
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (s[0][i] == t[i]) {
            continue;
        }

        int need = t[i] - 'a';

        int row = -1;
        int column = -1;

        // First try to find the needed character below row 0.
        if (!belowPos[need].empty()) {
            auto it = belowPos[need].begin();
            row = it->first;
            column = it->second;
        }
        // Otherwise, find it later in row 0.
        else {
            auto it = topPos[need].lower_bound(i + 1);
            if (it != topPos[need].end()) {
                row = 0;
                column = *it;
            }
        }

        if (row == 0) {
            // Operation type 1:
            // swap two columns in the same row.
            ans.push_back({1, 0, i, column});
            swapCells(0, i, 0, column);
        } else if (column == i) {
            // Operation type 2:
            // swap two rows in the same column.
            ans.push_back({2, 0, row, i});
            swapCells(0, i, row, i);
        } else {
            // First move the needed character to column i in its row.
            ans.push_back({1, row, column, i});
            swapCells(row, column, row, i);

            // Then move it up to row 0.
            ans.push_back({2, 0, row, i});
            swapCells(0, i, row, i);
        }
    }

    cout << ans.size() << '\n';

    for (auto op : ans) {
        cout << op[0] << ' ' << op[1] + 1 << ' ' << op[2] + 1 << ' '
             << op[3] + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}