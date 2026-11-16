#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        pos[A[i]] = i;
    }
    int min_pos = pos[0];
    int max_pos = pos[0];
    for (int i = 1; i < N; i++) {
        if (pos[i] > min_pos && pos[i] < max_pos) {
            cout << i + 1 << '\n';
            return;
        }
        min_pos = min(min_pos, pos[i]);
        max_pos = max(max_pos, pos[i]);
    }
    cout << N + 2 << '\n';
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}