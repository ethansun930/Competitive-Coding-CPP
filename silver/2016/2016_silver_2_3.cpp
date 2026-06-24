#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
using namespace std;

int abs(int n) {
    if (n >= 0) {
        return n;
    }
    return -n;
}
int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int X, Y, K, M;
    cin >> X >> Y >> K >> M;
    int ans = M;
    set<pair<int, int>> visited;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    while (!q.empty()) {
        pair<pair<int, int>, int> curr = q.front();
        q.pop();
        int turns = curr.second;
        if (turns > K) {
            continue;
        }
        pair<int, int> pails = curr.first;
        if (visited.find(pails) != visited.end()) {
            continue;
        }
        visited.insert(pails);
        ans = min(ans, abs(pails.first + pails.second - M));
        // cout << pails.first << ' ' << pails.second << '\n';
        q.push(make_pair(make_pair(pails.first, Y), turns + 1));
        q.push(make_pair(make_pair(X, pails.second), turns + 1));
        q.push(make_pair(make_pair(pails.first, 0), turns + 1));
        q.push(make_pair(make_pair(0, pails.second), turns + 1));
        if ((pails.first + pails.second) < X) {
            q.push(
                make_pair(make_pair(pails.first + pails.second, 0), turns + 1));
        } else {
            q.push(make_pair(make_pair(X, pails.first + pails.second - X),
                             turns + 1));
        }
        if ((pails.first + pails.second) < Y) {
            q.push(
                make_pair(make_pair(0, pails.first + pails.second), turns + 1));
        } else {
            q.push(make_pair(make_pair(pails.first + pails.second - Y, Y),
                             turns + 1));
        }
    }
    cout << ans << '\n';
    return 0;
}