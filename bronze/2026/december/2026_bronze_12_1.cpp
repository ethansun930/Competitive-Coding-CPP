#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long A, B, ca, cb, f;
    cin >> A >> B >> ca >> cb >> f;
    long long result = A + ca * (B / cb);
    if (result >= f) {
        cout << 0 << '\n';
        return;
    }
    long long a_needed = f - result - 1;
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
so
n = 0: A + ca * ((B + x)/cb) >= f
n = x: A + x + ca * (B/cb) >= f
x >= f - A - ca * (B/cb)
(B + x)/cb >= ceil((f - A)/ca) = (f - A - 1)/ca + 1
B + x >= cb((f - A - 1)/ca + 1)
x >= cb((f - A - 1)/ca + 1) - B
n = x - (cb * (x + B + 1)/cb - B - 1)
A + x - (cb * ((x + B + 1)/cb) - B - 1) + ca * ((x + B + 1)/cb - 1) >= f

*/