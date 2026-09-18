#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    vector<int> teams(N, 0);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < C; j++) {
            if (S[j] == 'G') {
                teams[i] += (1 << j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int maximum = 0;
        for (int j = 0; j < N; j++) {
            maximum = max(maximum, __builtin_popcount(teams[i] ^ teams[j]));
            if (maximum == C) {
                break;
            }
        }
        cout << maximum << '\n';
    }
    return 0;
}
/*
for every team, you run a BFS.
from 101, you can go to 100, 111, 001
and then you do things like that and start with the inverse of the number until
you reach the closest team, and that distance is C - the correct answer.
*/