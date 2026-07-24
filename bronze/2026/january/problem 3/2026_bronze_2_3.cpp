#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, Q;
    cin >> N >> Q;
    long long a[31];
    for (long long i = 0; i < 31; i++) {
        if (i < N) {
            cin >> a[i];
            if (i > 0) {
                a[i] = min(a[i], 2 * a[i - 1]);
            }
        } else {
            a[i] = 2 * a[i - 1];
        }
    }
    for (long long i = 31; i < N; i++) {
        long long x;
        cin >> x;
        a[30] = min(a[30], x);
    }
    for (long long i = 29; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1]);
    }
    for (long long i = 0; i < Q; i++) {
        long long x;
        cin >> x;
        long long ans = 0;
        for (long long j = 0; j < 31; j++) {
            ans = min(ans, a[j]);
            if ((x & (1 << j)) != 0) {
                ans += a[j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}