#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> breeds(N);
    for (int i = 0; i < N; i++) {
        cin >> breeds[i];
    }
    vector<int> Holsteins(N+1);
    vector<int> Guernseys(N+1);
    vector<int> Jerseys(N+1);
    Holsteins[0] = 0;
    Guernseys[0] = 0;
    Jerseys[0] = 0;
    for (int i = 1; i < N+1; i++) {
        if (breeds[i-1] == 1) {
            Holsteins[i] = Holsteins[i-1] + 1;
            Guernseys[i] = Guernseys[i-1];
            Jerseys[i] = Jerseys[i-1];
        }
        else if (breeds[i-1] == 2) {
            Holsteins[i] = Holsteins[i-1];
            Guernseys[i] = Guernseys[i-1] + 1;
            Jerseys[i] = Jerseys[i-1];
        }
        else {
            Holsteins[i] = Holsteins[i-1];
            Guernseys[i] = Guernseys[i-1];
            Jerseys[i] = Jerseys[i-1] + 1;
        }
    }
    vector<vector<int>> answers;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        answers.push_back({Holsteins[b] - Holsteins[a-1], Guernseys[b] - Guernseys[a-1], Jerseys[b] - Jerseys[a-1]});
    }
    for (const auto& ans : answers) {
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
    return 0;
}
/*
6 3
2
1
1
3
2
1
1 6
3 3
2 4
*/