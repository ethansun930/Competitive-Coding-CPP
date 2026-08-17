#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void factors(long long N, vector<long long>& possibles) {
    for (long long i = 1; i <= sqrt(static_cast<long double>(N)); i++) {
        if (N % i == 0) {
            possibles.push_back(i);
            possibles.push_back(N / i);
        }
    }
}
int main() {
    long long N;
    cin >> N;
    vector<long long> adup(N, 0);
    long long maxl = LLONG_MAX;
    for (long long i = 0; i < N; i++) {
        long long x;
        cin >> x;
        adup[i] = x;
        maxl = min(maxl, x / 4);
    }
    sort(adup.begin(), adup.end());
    vector<long long> a;
    for (long long i = 0; i < N; i++) {
        if (i == 0 || adup[i - 1] != adup[i]) {
            a.push_back(adup[i]);
        }
    }
    N = a.size();
    if (N <= 3) {
        cout << (maxl * (maxl + 1)) / 2 << '\n';
        return 0;
    }
    vector<long long> possibles;
    for (long long i = 0; i < 4; i++) {
        for (long long j = i + 1; j < 4; j++) {
            factors(a[j] - a[i], possibles);
        }
    }
    sort(possibles.begin(), possibles.end());
    long long ans = 0;
    for (long long i = possibles.size() - 1; i >= 0; i--) {
        if (i != possibles.size() - 1 && possibles[i] == possibles[i + 1]) {
            continue;
        }
        unordered_set<long long> rems;
        for (long long j = 0; j < N; j++) {
            rems.insert(a[j] % possibles[i]);
        }
        if (rems.size() <= 3) {
            ans += possibles[i];
        }
    }
    cout << ans << '\n';
    return 0;
}