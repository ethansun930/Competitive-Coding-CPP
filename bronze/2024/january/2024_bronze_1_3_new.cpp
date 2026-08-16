#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N + 2, 0);
    for (long long i = 2; i < N + 2; i++) {
        cin >> a[i];
    }
    vector<long long> n(N + 1, 0);
    for (long long i = 0; i < N + 1; i++) {
        n[i] = a[i + 1] - a[i];
    }
    int ans = 0;
    for (long long i = 0; i < N; i++) {
        ans += abs(n[i + 1] - n[i]);
    }
    cout << ans << '\n';
    return 0;
}