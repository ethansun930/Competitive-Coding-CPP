#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, T;
    cin >> N >> T;
    vector<long long> d(N);
    vector<long long> b(N);
    for (long long i = 0; i < N; i++) {
        cin >> d[i] >> b[i];
        d[i]--;
    }
    long long amount = 0;
    long long ans = 0;
    for (long long i = 0; i < N - 1; i++) {
        amount += b[i];
        long long new_amount = amount;
        new_amount -= (d[i + 1] - d[i]);
        new_amount = max(new_amount, 0LL);
        ans += (amount - new_amount);
        amount = new_amount;
    }
    amount += b[N - 1];
    long long new_amount = amount;
    new_amount -= (T - d[N - 1]);
    new_amount = max(new_amount, 0LL);
    ans += (amount - new_amount);
    amount = new_amount;
    cout << ans << '\n';
}