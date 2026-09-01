#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> worst_e(M, INT_MAX);
    vector<int> worst_o(M, INT_MAX);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                worst_e[i] = min(worst_e[i], x);
                worst_o[i] = min(worst_o[i], -x);
            } else {
                worst_e[i] = min(worst_e[i], -x);
                worst_o[i] = min(worst_o[i], x);
            }
        }
    }
    vector<int> needed(M + 1, 1);
    for (int i = M - 1; i >= 0; i--) {
        needed[i] = max(1, needed[i + 1] - max(worst_e[i], worst_o[i]));
    }
    int curr = N;
    if (N < needed[0]) {
        cout << "-1" << '\n';
        return;
    }
    for (int i = 0; i < M - 1; i++) {
        if (curr + worst_e[i] >= needed[i + 1]) {
            cout << "Even" << ' ';
            curr += worst_e[i];
        } else {
            cout << "Odd" << ' ';
            curr += worst_o[i];
        }
    }
    if (curr + worst_e[M - 1] >= needed[M]) {
        cout << "Even";
        curr += worst_e[M - 1];
    } else {
        cout << "Odd";
        curr += worst_o[M - 1];
    }
    cout << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}