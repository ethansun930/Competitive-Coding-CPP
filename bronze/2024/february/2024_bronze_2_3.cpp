#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    vector<int> close(N);
    for (int i = 0; i < N; i++) {
        close[i] = max(0, c[i] - t[i]);
    }
    sort(close.begin(), close.end());
    int curr = 0;
    vector<int> amount(1000001, 0);
    for (int i = 0; i < 1000001; i++) {
        if (i > 0) {
            amount[i] = amount[i - 1];
        }
        while (curr < N && close[curr] == i) {
            amount[i]++;
            curr++;
        }
    }
    while (Q--) {
        int S, V;
        cin >> V >> S;
        if (N - amount[S] >= V) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}