#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int k) {
    int N;
    cin >> N;
    int np = N % 2;
    string S;
    cin >> S;
    if (k == 0) {
        cout << "YES" << '\n';
        return;
    }
    cout << "YES" << '\n';
    string typed = "";
    int O = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (O == 0) {
            typed.push_back(S[i]);
            if (S[i] == 'O') {
                O = 1;
            }
        } else {
            if (S[i] == 'M') {
                typed.push_back('O');
                O = 0;
            } else {
                typed.push_back('M');
            }
        }
    }
    reverse(typed.begin(), typed.end());
    cout << typed << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, k;
    cin >> T >> k;
    for (int i = 0; i < T; i++) {
        solve(k);
    }
    return 0;
}