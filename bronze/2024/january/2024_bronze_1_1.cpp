#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> h(N);
    unordered_set<int> possible;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        h[i]--;
    }
    vector<vector<int>> prefix(N + 1, vector<int>(N, 0));
    for (int i = 1; i <= N; i++) {
        prefix[i][h[i - 1]]++;
        for (int j = 0; j < N; j++) {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
    for (int i = 3; i <= N; i++) {
        for (int j = 0; j <= (N - i); j++) {
            int type = -1;
            for (int k = 0; k < N; k++) {
                if ((prefix[i + j][k] - prefix[j][k]) >= (i + 1) / 2) {
                    type = k;
                }
            }
            cout << type << ' ';
            if (type != -1) {
                possible.insert(type);
            }
        }
        cout << '\n';
    }
    if (possible.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    int x = *possible.begin();
    cout << x;
    possible.erase(x);
    for (const int& i : possible) {
        cout << ' ' << i;
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