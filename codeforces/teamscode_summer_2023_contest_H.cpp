#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (long long i = 1; i <= N; i++) {
        cin >> a[i - 1];
        a[i - 1] *= (i * (N - i + 1));
    }
    vector<long long> b(N);
    for (long long i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        ans += (a[i] * b[i]);
    }
    cout << ans << '\n';
    return 0;
}
/*
we have just the sum from k = 0 to k = N
of k * (n - k + 1) * ak * bk
*/