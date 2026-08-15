#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, C;
    cin >> T >> C;
    vector<int> t(T);
    for (int i = 0; i < T; i++) {
        cin >> t[i];
    }
    string S;
    cin >> S;
    vector<int> com(C, 0);
    for (int i = 0; i < C; i++) {
        if (S[i] == 'L') {
            com[i] = -1;
        } else if (S[i] == 'R') {
            com[i] = 1;
        }
    }
}