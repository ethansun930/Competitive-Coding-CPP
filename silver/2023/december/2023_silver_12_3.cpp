// help from chatgpt
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int T, C;
    cin >> T >> C;
    vector<bool> t(2 * C + 1, false);
    for (int i = 0; i < T; i++) {
        int x;
        cin >> x;
        t[x + C] = true;
    }
    string S;
    cin >> S;
    vector<int> com(C, 0);
    for (int i = 0; i < C; i++) {
        if (S[i] == 'L') {
            com[i] = -1;
        } else if (S[i] == 'R') {
            com[i] = 1;
        }
    }
    vector<int> pos(C, C);
    for (int i = 1; i < C; i++) {
        pos[i] = pos[i - 1] + com[i - 1];
    }
    vector<array<int, 5>> suffix(2 * C + 1);
    int hit_targets[5] = {0};
    for (int i = 0; i < C; i++) {
        if (com[i] != 0) {
            continue;
        }
        for (int d = -2; d <= 2; d++) {
            if ((pos[i] + d) < 0 || (pos[i] + d) > 2 * C || !t[pos[i] + d]) {
                continue;
            }
            if (suffix[pos[i] + d][d + 2] == 0) {
                hit_targets[d + 2]++;
            }
            suffix[pos[i] + d][d + 2]++;
        }
    }
    int ans = hit_targets[2];
    vector<bool> prefix(2 * C + 1);
    for (int i = 0; i < C; i++) {
        if (com[i] == 0) {
            for (int d = -2; d <= 2; d++) {
                if ((pos[i] + d) < 0 || (pos[i] + d) > 2 * C ||
                    !t[pos[i] + d]) {
                    continue;
                }
                suffix[pos[i] + d][d + 2]--;
                if (suffix[pos[i] + d][d + 2] == 0 && !prefix[pos[i] + d]) {
                    hit_targets[d + 2]--;
                }
            }
        }
        int new_com = (com[i] + 2) % 3 - 1;
        int d = new_com - com[i];
        int score = hit_targets[d + 2];
        if (new_com == 0) {
            if (pos[i] >= 0 && pos[i] <= 2 * C && t[pos[i]] &&
                !prefix[pos[i]] && suffix[pos[i]][d + 2] == 0) {
                score++;
            }
        }
        cout << i << ' ' << score << '\n';
        ans = max(ans, score);
        new_com = (com[i] + 2) % 3 - 1;
        d = new_com - com[i];
        score = hit_targets[d + 2];
        if (new_com == 0) {
            if (pos[i] >= 0 && pos[i] <= 2 * C && t[pos[i]] &&
                !prefix[pos[i]] && suffix[pos[i]][d + 2] == 0) {
                score++;
            }
        }
        cout << i << ' ' << score << '\n';
        ans = max(ans, score);
        if (com[i] == 0) {
            if (pos[i] >= 0 && pos[i] <= 2 * C && t[pos[i]] &&
                !prefix[pos[i]]) {
                prefix[pos[i]] = true;
                for (int d = -2; d <= 2; d++) {
                    if (!suffix[pos[i]][d + 2]) {
                        hit_targets[d + 2]++;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}