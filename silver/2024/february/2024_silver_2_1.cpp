#include <iostream>
#include <vector>
using namespace std;

struct rect {
    int x1, x2, y1, y2;
};
void solve() {
    int N, X;
    cin >> N >> X;
    vector<rect> targets(N);
    for (int i = 0; i < N; i++) {
        targets[i].x1 = X;
        cin >> targets[i].y1 >> targets[i].y2 >> targets[i].x1;
    }
    vector<int> s(4 * N);
    for (int i = 0; i < 4 * N; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<int> bottom_left;
    vector<int> bottom_right;
    for (int i = 0; i < 4 * N; i++) {
        if (s[i] > 0) {
            bottom_left.push_back(s[i]);
        } else {
            bottom_right.push_back(s[i]);
        }
    }
    if (bottom_left.size() < N || bottom_right.size() < N) {
        cout << -1 << '\n';
        return;
    }
    vector<int> top_right;
    for (int i = 0; i < N; i++) {
        top_right.push_back(bottom_left.back());
        bottom_left.pop_back();
    }
    vector<int> top_left;
    for (int i = 0; i < bottom_right.size() - N; i++) {
        top_left.push_back(bottom_right.back());
        bottom_right.pop_back();
    }
}
/*
let pos_s be positive slope, neg_s be negative.
pos_s.size() >= N and neg_s.size() >= N to work.
the last N items of neg_s should go to the top right corners,
first N items of pos_s be in bottom right
the rest of it go to the left corners.
top right corner:
place the smallest slopes in the bottomest corners.
bottom right:
place the biggest slopes in the highest corners.
left corners:
smallest slopes in lowest corners.
*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}