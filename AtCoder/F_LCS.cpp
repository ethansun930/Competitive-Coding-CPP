#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int s_len = s.length();
    int t_len = t.length();
    vector<int> curr_row(t_len + 1, 0);
    vector<int> prev_row(t_len + 1, 0);
    // 0: vertical, 1: horizontal, 2: diagnal
    vector<vector<int>> moves(s_len + 1, vector<int>(t_len + 1, 0));
    for (int i = 1; i < s_len + 1; i++) {
        for (int j = 1; j < t_len + 1; j++) {
            if (s[i - 1] == t[j - 1]) {
                curr_row[j] = prev_row[j - 1];
                curr_row[j]++;
                moves[i][j] = 2;
            } else {
                if (prev_row[j] >= curr_row[j - 1]) {
                    curr_row[j] = prev_row[j];
                    moves[i][j] = 0;
                } else {
                    curr_row[j] = curr_row[j - 1];
                    moves[i][j] = 1;
                }
            }
        }
        prev_row = curr_row;
    }
    string ans = "";
    int i = s.length();
    int j = t.length();
    while ((i != 0) && (j != 0)) {
        if (moves[i][j] == 2) {
            ans = s[i - 1] + ans;
            i--;
            j--;
        } else if (moves[i][j] == 0) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << '\n';
    return 0;
}