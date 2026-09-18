#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int curr = 0;
    vector<int> p(N + 1, 0);
    for (int i = 0; i < N; i++) {
        curr += (i + 1) * a[i];
        p[i + 1] = p[i] + a[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int i, j;
        cin >> i >> j;
        if (a[i] == j) {
            cout << curr << '\n';
            continue;
        }
        if (a[i] < j) {
            int new_position = 0;
            for (int k = i; k < N; k++) {
                if (a[k] >= j) {
                    new_position = k;
                    break;
                }
            }
        }
    }
}
/*
calculate difference between new query and old version.
*/