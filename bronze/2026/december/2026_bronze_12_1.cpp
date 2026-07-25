#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int A, B, ca, cb, f;
    cin >> A >> B >> ca >> cb >> f;
    if (cb >= ca) {
        cout << max(((f * cb - A * cb - B * ca - 1) / ca + 1), 0) << '\n';
    } else {
        cout << 0 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
/*
with a chips type a and b chips type b, you can get a + ca * (b/cb) chips type
a.
start with A chips type a and B chips type b, you get another n chips type a
and x - n chips type b for some random integer n.
if you want to end up with at least f chips type a,
A + n + ca * ((B + x - n)/cb) >= f for all n.
(cb - ca) * n >= f * cb - A * cb - B * ca - x * ca.
cb > ca:
f * cb <= A * cb + B * ca + x * ca.
cb = ca:
same thing as earlier.
cb < ca:
(f * cb - A * cb - B * ca - x * ca)/(ca - cb) >= x
f * cb - A * cb - B * ca - x * ca >= ca * x - cb * x
*/