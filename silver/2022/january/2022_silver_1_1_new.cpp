#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    vector<pair<long long, long long>> A, B;
    long long curr = a;
    long long cost = 0;
    A.push_back({curr, cost});
    while (curr > 1) {
        if (curr % 2 == 0) {
            curr /= 2;
        } else {
            curr++;
        }
        cost++;
        A.push_back({curr, cost});
    }
    curr = b;
    cost = 0;
    B.push_back({curr, cost});
    while (curr > 1) {
        if (curr % 2 == 0) {
            curr /= 2;
        } else {
            curr--;
        }
        cost++;
        B.push_back({curr, cost});
    }
    long long ans = LLONG_MAX;
    for (pair<long long, long long> x : A) {
        for (pair<long long, long long> y : B) {
            if (x.first <= y.first) {
                ans = min(ans, (y.first - x.first + x.second + y.second));
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}