#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(K);
    vector<bool> aused(N, true);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
        aused[a[i] - 1] = false;
    }
    vector<int> b(N, -1);
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        b[x - 1] = i;
    }
    int ans = 0;
    vector<int> answers(2 * K, 0);
    for (int i = 0; i < K; i++) {
        int j = b[a[i] - 1];
        if (j == -1) {
            continue;
        }
        answers[(i - j + K) % K]++;
        answers[K + (i + j) % K]++;
    }
    for (int i = 0; i < 2 * K; i++) {
        ans = max(ans, answers[i]);
    }
    for (int i = 0; i < N; i++) {
        if (b[i] == -1 && aused[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}