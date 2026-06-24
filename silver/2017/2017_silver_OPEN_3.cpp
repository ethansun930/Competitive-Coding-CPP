#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void fill(vector<vector<char>>& grid, vector<vector<int>>& markings, int l,
          int r, int u, int d, int x, int y, int mark) {
    if (markings[x][y] != 0) {
        return;
    }
    markings[x][y] = mark;
    int dir[5] = {1, 0, -1, 0, 1};
    for (int t = 0; t < 4; t++) {
        int new_x = x + dir[t];
        int new_y = y + dir[t + 1];
        if (l <= new_x && new_x <= r && u <= new_y && new_y <= d &&
            grid[new_x][new_y] == grid[x][y]) {
            fill(grid, markings, l, r, u, d, new_x, new_y, mark);
        }
    }
}
bool is_pcl(vector<vector<char>>& grid, int l, int r, int u, int d) {
    int N = grid.size();
    vector<vector<int>> markings(N, vector<int>(N, 0));
    map<char, int> colors_put;
    int mark = 1;
    for (int i = l; i <= r; i++) {
        for (int j = u; j <= d; j++) {
            if (markings[i][j] == 0) {
                fill(grid, markings, l, r, u, d, i, j, mark);
                mark++;
                if (colors_put.count(grid[i][j]) == 0) {
                    colors_put[grid[i][j]] = 1;
                } else {
                    colors_put[grid[i][j]]++;
                }
            }
        }
    }
    if (colors_put.size() != 2) {
        return false;
    }
    auto it = colors_put.begin();
    if (it->second == 1) {
        it++;
        if (it->second >= 2) {
            return true;
        }
    } else if (it->second >= 2) {
        it++;
        if (it->second == 1) {
            return true;
        }
    }
    return false;
}
int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> pcls;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            for (int u = 0; u < N; u++) {
                for (int d = u; d < N; d++) {
                    if (is_pcl(grid, l, r, u, d)) {
                        pcls.push_back({l, r, u, d});
                    }
                }
            }
        }
    }
    int count = 0;
    for (int j = 0; j < pcls.size(); j++) {
        bool contained = false;
        for (int i = 0; i < pcls.size(); i++) {
            if (i == j) {
                continue;
            }
            vector<int> I = pcls[i];
            vector<int> J = pcls[j];
            if ((I[0] <= J[0]) && (I[1] >= J[1]) && (I[2] <= J[2]) &&
                (I[3] >= J[3])) {
                contained = true;
                break;
            }
        }
        if (!contained) {
            count++;
        }
    }
    // for (int i = 0; i < pcls.size(); i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << (*next(pcls.begin(), i))[j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << pcls.size() << '\n';
    cout << count << '\n';
    return 0;
}