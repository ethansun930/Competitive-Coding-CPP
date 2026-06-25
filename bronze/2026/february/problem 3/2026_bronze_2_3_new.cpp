#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve() {
    int N, M;
    cin >> N >> M;
    string t;
    cin >> t;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    vector<vector<int>> ans;
    for (int i = 0; i < M; i++) {
        if (s[0][i] == t[i]) {
            continue;
        }
        int row = -1;
        int column = -1;
        for (int j = 1; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (s[j][k] == t[i]) {
                    row = j;
                    column = k;
                    break;
                }
            }
            if (row != -1) {
                break;
            }
        }
        if (row == -1) {
            for (int j = i + 1; j < M; j++) {
                if (s[0][j] == t[i]) {
                    row = 0;
                    column = j;
                    break;
                }
            }
            // not supposed to be here, this will break through the entire loop
            // if (row != -1) {
            //     break;
            // }
        }
        if (row == 0) {
            ans.push_back({1, 0, column, i});
            swap(s[0][column], s[0][i]);
            continue;
        } else if (column == i) {
            ans.push_back({2, 0, row, i});
            swap(s[0][i], s[row][i]);
        } else {
            ans.push_back({1, row, column, i});
            ans.push_back({2, 0, row, i});
            swap(s[row][column], s[row][i]);
            swap(s[0][i], s[row][i]);
        }
    }
    int ans_size = ans.size();
    cout << ans_size << '\n';
    for (int i = 0; i < ans_size; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] + 1 << ' ' << ans[i][2] + 1 << ' '
             << ans[i][3] + 1 << '\n';
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
