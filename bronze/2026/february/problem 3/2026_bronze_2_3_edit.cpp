#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void add_cell(vector<string>& s, set<int> top_row[],
              set<pair<int, int>> other[], int row, int col) {
    int ch = s[row][col] - 'a';
    if (row == 0) {
        top_row[ch].insert(col);
    } else {
        other[ch].insert(make_pair(row, col));
    }
}
void remove_cell(vector<string>& s, set<int> top_row[],
                 set<pair<int, int>> other[], int row, int col) {
    int ch = s[row][col] - 'a';
    if (row == 0) {
        top_row[ch].erase(col);
    } else {
        other[ch].erase(make_pair(row, col));
    }
}
void swap_cells(vector<string>& s, set<int> top_row[],
                set<pair<int, int>> other[], int row1, int col1, int row2,
                int col2) {
    remove_cell(s, top_row, other, row1, col1);
    remove_cell(s, top_row, other, row2, col2);
    swap(s[row1][col1], s[row2][col2]);
    add_cell(s, top_row, other, row1, col1);
    add_cell(s, top_row, other, row2, col2);
}
void solve() {
    int N, M;
    cin >> N >> M;
    string t;
    cin >> t;
    vector<string> s(N);
    set<int> top_row[26];
    set<pair<int, int>> other[26];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < M; j++) {
            int ch = s[i][j] - 'a';
            if (i == 0) {
                top_row[ch].insert(j);
            } else {
                other[ch].insert(make_pair(i, j));
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < M; i++) {
        if (s[0][i] == t[i]) {
            continue;
        }
        int ch = t[i] - 'a';
        int row = -1;
        int col = -1;
        if (!other[ch].empty()) {
            pair<int, int> row_col = *other[ch].begin();
            row = row_col.first;
            col = row_col.second;
        } else {
            auto it = top_row[ch].lower_bound(i);
            if (it != top_row[ch].end()) {
                col = *it;
                row = 0;
            }
        }
        if (row == 0) {
            swap_cells(s, top_row, other, 0, i, 0, col);
            ans.push_back({1, 1, i + 1, col + 1});
        } else if (col == i) {
            swap_cells(s, top_row, other, 0, i, row, i);
            ans.push_back({2, 1, row + 1, i + 1});
        } else {
            swap_cells(s, top_row, other, row, i, row, col);
            ans.push_back({1, row + 1, i + 1, col + 1});
            swap_cells(s, top_row, other, 0, i, row, i);
            ans.push_back({2, 1, row + 1, i + 1});
        }
    }
    int ans_size = ans.size();
    cout << ans_size << '\n';
    for (int i = 0; i < ans_size; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' '
             << ans[i][3] << '\n';
    }
}
int main() {
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
