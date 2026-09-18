#include <iostream>
#include <vector>
using namespace std;

void solve(int C) {
    int N;
    cin >> N;
    string l, r;
    cin >> l >> r;
    int l_n = 0;
    int r_n = 0;
    for (int i = 0; i < N; i++) {
        if (l[i] == 'N') {
            l_n++;
        }
        if (r[i] == 'N') {
            r_n++;
        }
    }
    if (l_n != r_n) {
        cout << "NO" << '\n';
        return;
    }
    if (l_n % 2 == 1) {
        cout << "NO" << '\n';
        return;
    }
    if (C == 0) {
        cout << "YES" << '\n';
        return;
    }
}
int main() {
    int T, C;
    cin >> T >> C;
    while (T--) {
        solve(C);
    }
    return 0;
}
/*
NN
NN
NN
NJ
JJ
JN
*/