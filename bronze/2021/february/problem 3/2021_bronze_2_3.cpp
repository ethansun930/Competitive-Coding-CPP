#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<char, int> directions = {
    {'N', 1},
    {'E', 2},
    {'S', 3},
    {'W', 4}
};
int main() {
    int N;
    cin >> N;
    string pathway;
    vector<string> answers;
    int R;
    int L;
    for (int i = 0; i < N; i++) {
        cin >> pathway;
        R = 0;
        L = 0;
        for (int i = 0; i < pathway.size() - 1; i++) {
            if (pathway[i] == pathway[i+1]) {
                continue;
            }
            if (directions[pathway[i]] < directions[pathway[i+1]]) {
                R++;
            }
            else {
                L++;
            }
        }
        // cout << R << " " << L << "\n";
        if (R > L) {
            answers.push_back("CW");
        }
        else {
            answers.push_back("CCW");
        }
    }
    for (const string& ans : answers) {
        cout << ans << "\n";
    }
    return 0;
}
/*
CW : RRR, RRLLRRLRRLRRLLL, RRRR            3R 0L, 8R 7L, 4R 0L      0, 7, 0
CCW : LLL, LLLLRRRLLLL, LLLL               0R 3L, 3R 8L, 0R 4L      0, 2, 0
*/