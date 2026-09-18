#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int N, C, P;
    cin >> N >> C >> P;
    vector<string> types[4];
    // stored as types[0] = nouns, types[1] = transitive_verbs, types[2] =
    // intransitive_verbs, types[3] = cunjunction
    for (int i = 0; i < N; i++) {
        string word, type;
        cin >> word >> type;
        if (type[0] == 'n') {
            types[0].push_back(word);
        } else if (type[0] == 't') {
            types[1].push_back(word);
        } else if (type[0] == 'i') {
            types[2].push_back(word);
        } else {
            types[3].push_back(word);
        }
    }
}
/*
only care about amount of each type.
*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}