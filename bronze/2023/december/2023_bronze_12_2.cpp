#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<bool> sick(N, false);
    int cows_sick = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            sick[i] = true;
        }
        if (sick[i]) {
            cows_sick++;
        }
    }
    int curr = 0;
    int steps = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (sick[i]) {
            curr++;
        } else {
            if (i != 0 && curr == i) {
                steps = min(steps, curr - 1);
                curr = 0;
            } else if (curr != 0) {
                steps = min(steps, (curr - 1) / 2);
                curr = 0;
            }
        }
    }
    if (curr != 0) {
        steps = min(steps, curr - 1);
        curr = 0;
    }
    if (steps == INT_MAX) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (sick[i]) {
            curr++;
        } else {
            if (curr != 0) {
                ans += (curr + 2 * steps) / (2 * steps + 1);
                curr = 0;
            }
        }
    }
    if (curr != 0) {
        ans += (curr + 2 * steps) / (2 * steps + 1);
        curr = 0;
    }
    cout << ans << '\n';
    return 0;
}