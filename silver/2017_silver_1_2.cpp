#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> movements(N);
    for (int i = 0; i < N; i++) {
        char x;
        cin >> x;
        if (x == 'H') {
            movements[i] = 0;
        }
        else if (x == 'P') {
            movements[i] = 1;
        }
        else {
            movements[i] = 2;
        }
    }
    vector<int> prefix_sums(N);
    vector<int> suffix_sums(N);
    int curr[3] = {0, 0, 0};
    for (int i = 0; i < N; i++) {
        curr[movements[i]]++;
        prefix_sums[i] = max(curr[0], curr[1]);
        prefix_sums[i] = max(prefix_sums[i], curr[2]);
    }
    curr[0] = 0;
    curr[1] = 0;
    curr[2] = 0;
    for (int i = N - 1; i >= 0; i--) {
        suffix_sums[i] = max(curr[0], curr[1]);
        suffix_sums[i] = max(suffix_sums[i], curr[2]);
        curr[movements[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, prefix_sums[i] + suffix_sums[i]);
    }
    cout << ans << '\n';
    return 0;
}
/*
movements = {1, 1, 0, 1, 2}
curr = {1, 3, 1}
prefixs = {1, 2, 2, 3, 3}
suffixs = {3, 2, 1, 1, 1}
*/