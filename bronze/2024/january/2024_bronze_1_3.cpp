#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (long long i = 0; i < N; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    long long updater = 0;
    long long adder = 0;
    for (long long i = 0; i < N; i++) {
        ans += abs(a[i] - updater);
        a[i] -= updater;
        updater += a[i];
        adder += a[i];
        updater += adder;
    }
    cout << ans << '\n';
}

/*
n = 3:
ans += abs(a[0]);
a[1] -= (a[0] * 2)
a[2] -= (a[0] * 3)
ans += abs(a[1]);
a[2] -= (a[1] * 2)
ans += abs(a[2]);
ans = abs(a[0]) + abs(a[1] - 2a[0]) + abs(a[2] - 3a[0] - 2(a[1] - 2a[0]))
*/