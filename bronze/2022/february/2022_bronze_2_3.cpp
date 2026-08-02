#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector<string>& blocks) {
    string word;
    cin >> word;
    vector<int> order = {0, 1, 2, 3};
    do {
        bool ok = true;
        for (int i = 0; i < word.length(); i++) {
            bool match = false;
            for (int j = 0; j < 6; j++) {
                if (blocks[order[i]][j] == word[i]) {
                    match = true;
                    break;
                }
            }
            if (!match) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
            return;
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << "NO" << '\n';
    return;
}
int main() {
    int N;
    cin >> N;
    vector<string> blocks(4);
    cin >> blocks[0] >> blocks[1] >> blocks[2] >> blocks[3];
    for (int i = 0; i < N; i++) {
        solve(blocks);
    }
    return 0;
}