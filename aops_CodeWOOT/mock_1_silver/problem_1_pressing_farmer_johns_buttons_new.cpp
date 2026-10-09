#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> press_effects;
    press_effects.push_back({3 << (N - 2), 1 << (N - 1)});
    for (int i = 1; i <= N; i++) {
        press_effects.push_back({7 << (N - i - 2), 1 << (N - i - 1)});
    }
    press_effects.push_back({3, 1});
    vector<int> C(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            C[i] <<= 1;
            if (s[j] == '1') {
                C[i] += 1;
            }
        }
    }
    int ans = INT_MAX;
    for (int t = 0; t < (1 << N); t++) {
        int curr_ans = 0;
        int prev = t;
        int curr = C[1];
        for (int i = 1; i <= N; i++) {
            int new_curr = curr;
            int next = C[i + 1];
            for (int j = N - 1; j >= 0; j--) {
                if (prev % 2 == 1) {
                    new_curr ^= press_effects[j].first;
                    next ^= press_effects[j].second;
                    curr_ans++;
                }
                prev >>= 1;
            }
            prev = new_curr;
            curr = next;
        }
        if (prev == 0) {
            ans = min(ans, curr_ans);
        }
    }
    cout << ans << '\n';
    return 0;
}