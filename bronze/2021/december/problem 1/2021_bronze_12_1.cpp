#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string x;
    cin >> x;
    vector<int> breeds(N, 0);
    for (int i = 0; i < N; i++) {
        if (x[i] == 'H') {
            breeds[i] = 1;
        }
    }
    vector<int> g_sums(N + 1, 0);
    vector<int> h_sums(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        g_sums[i] = g_sums[i - 1];
        h_sums[i] = h_sums[i - 1];
        if (breeds[i - 1] == 0) {
            g_sums[i]++;
        } else {
            h_sums[i]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j++) {
            if ((g_sums[j + 1] - g_sums[i] == 1) ||
                (h_sums[j + 1] - h_sums[i] == 1)) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}