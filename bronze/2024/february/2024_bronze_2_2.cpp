#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<long long> a(N);
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool same = true;
    for (long long i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << sum << '\n';
        return 0;
    }
    vector<long long> break_sections;
    for (long long i = 0; i < N; i++) {
        if (S[i] == 'L' && S[(i + 1) % N] == 'R') {
            break_sections.push_back(i);
        }
    }
    long long total_loss = 0;
    break_sections.push_back(break_sections[0] + N);
    for (long long i = 0; i < break_sections.size() - 1; i++) {
        long long loss = 0;
        for (long long j = break_sections[i] + 1; j <= break_sections[i + 1];
             j++) {
            if (S[j % N] == 'R' && S[(j + 1) % N] == 'L') {
                total_loss += min(loss, M);
                loss = 0;
                continue;
            } else if (S[j % N] == 'L' && S[(j + N - 1) % N] == 'R') {
                continue;
            } else {
                loss += a[j % N];
            }
        }
        total_loss += min(loss, M);
    }
    cout << sum - total_loss << '\n';
}
/*
for every two LR's, you basically have a seperate "island", and then the islands
only have the outside two edges lose milk.
*/