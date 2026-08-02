#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> d(N);
    for (long long i = 0; i < N; i++) {
        cin >> d[i];
    }
    long long ans = K + 1;
    for (long long i = 1; i < N; i++) {
        ans += min(K + 1, d[i] - d[i - 1]);
    }
    cout << ans << '\n';
}