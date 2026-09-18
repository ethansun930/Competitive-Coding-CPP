#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int parity = 0;
    if (S[0] == 'F' || S[N - 1] == 'F') {
        parity = -1;
    }
    int min = 0;
    int max = 0;
    int curr = 0;
    vector<pair<int, int>> f_intervals;
    if (S[0] != 'F' && S[1] == 'F') {
        f_intervals.push_back({1, -1});
    }
    if (S[0] == 'F') {
        f_intervals.push_back({0, -1});
    }
    for (int i = 1; i < N - 1; i++) {
        if (S[i] == 'F') {
            continue;
        }
        if (S[i - 1] == 'F') {
            f_intervals.back().second = i - 1;
        }
        if (S[i + 1] == 'F') {
            f_intervals.push_back({i + 1, -1});
        }
    }
    if (S[N - 1] == 'F') {
        f_intervals.back().second = N - 1;
    } else if (S[N - 2] == 'F') {
        f_intervals.back().second = N - 2;
    }

    return 0;
}
/*
BFE: 1
BFB: 0 or 2
BFFB: 1 or 3
BFFE: 0 or 2
BFFFB: 0 or 2 or 4
BFFFE: 1 or 3
start with:
FB: 0, 1
FFB: 0, 1, 2
split into "islands" of F, each of them seperate case work.
*/