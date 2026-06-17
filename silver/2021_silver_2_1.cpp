#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int d[5] = {1, 0, -1, 0, 1};
bool has_cow[3000][3000] = {};
void uncomfortable(int x, int y, queue<pair<int, int>>& q, int& ans) {
    if (!has_cow[x][y]) {
        return;
    }
    int neighbors = 0;
    int new_x = 0;
    int new_y = 0;
    for (int t = 0; t < 4; t++) {
        if (has_cow[x + d[t]][y + d[t + 1]]) {
            neighbors++;
        } else {
            new_x = x + d[t];
            new_y = y + d[t + 1];
        }
    }
    if (neighbors == 3) {
        q.push(make_pair(new_x, new_y));
        has_cow[new_x][new_y] = true;
        ans++;
    }
    return;
}
int main() {
    cin.tie(NULL);
    int N;
    cin >> N;
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        if (has_cow[x][y]) {
            ans--;
        } else {
            has_cow[x][y] = true;
            q.push(make_pair(x, y));
        }
        while (!q.empty()) {
            pair<int, int> cow = q.front();
            q.pop();
            uncomfortable(cow.first, cow.second, q, ans);
            for (int t = 0; t < 4; t++) {
                uncomfortable(cow.first + d[t], cow.second + d[t + 1], q, ans);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}