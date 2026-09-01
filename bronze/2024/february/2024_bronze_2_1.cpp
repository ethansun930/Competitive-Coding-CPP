#include <iostream>
#include <vector>
using namespace std;

void solve() {
    string S;
    cin >> S;
    if (S[S.length() - 1] == '0') {
        cout << 'E' << '\n';
    } else {
        cout << 'B' << '\n';
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
strategy when there is a winning state: any one digit number is a palindrome, so
you subtract it's unit digit, makking a losing state. when you are in a losing
state, you can't subtract 0, so you have to make it a winning state
*/