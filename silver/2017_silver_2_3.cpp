#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
void mark_land(vector<vector<set<pair<int, int>>>>& roads,
               vector<vector<int>>& land_markings, int x, int y, int mark) {
    if (x < 0 || x >= land_markings.size() || y < 0 ||
        y >= land_markings.size() || land_markings[x][y] != 0) {
        return;
    }
    land_markings[x][y] = mark;
    int dir[5] = {0, 1, 0, -1, 0};
    for (int t = 0; t < 4; t++) {
        if (roads[x][y].find(make_pair(x + dir[t], y + dir[t + 1])) ==
            roads[x][y].end()) {
            mark_land(roads, land_markings, x + dir[t], y + dir[t + 1], mark);
        }
    }
}
int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int N, K, R;
    cin >> N >> K >> R;
    vector<vector<set<pair<int, int>>>> roads(N,
                                              vector<set<pair<int, int>>>(N));
    for (int i = 0; i < R; i++) {
        int r, c, rp, cp;
        cin >> r >> c >> rp >> cp;
        r--;
        c--;
        rp--;
        cp--;
        roads[r][c].insert(make_pair(rp, cp));
        roads[rp][cp].insert(make_pair(r, c));
    }
    vector<pair<int, int>> cow_coordinates;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cow_coordinates.push_back(make_pair(x, y));
    }
    int mark = 1;
    vector<vector<int>> land_markings(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (land_markings[i][j] == 0) {
                mark_land(roads, land_markings, i, j, mark);
                mark++;
            }
        }
    }
    vector<int> cow_marks;
    for (int i = 0; i < K; i++) {
        cow_marks.push_back(
            land_markings[cow_coordinates[i].first][cow_coordinates[i].second]);
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            if (cow_marks[i] != cow_marks[j]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}