#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N, 0);
    vector<int> t(N + 2, 0);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for (int i = 1; i < N + 1; i++) {
        cin >> t[i];
        t[i] = t[i] - p[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= N + 1; i++) {
        ans += max(0, t[i] - t[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}