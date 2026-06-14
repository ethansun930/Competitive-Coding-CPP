#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<char>> grid(x, vector<char>(y));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> paths(x, vector<int>(y));
    paths[0][0] = 1;
    for (int i = 1; i < x; i++) {
        if (grid[i][0] == '#') {
            paths[i][0] = 0;
        } else {
            paths[i][0] = paths[i - 1][0];
        }
    }
    for (int i = 1; i < y; i++) {
        if (grid[0][i] == '#') {
            paths[0][i] = 0;
        } else {
            paths[0][i] = paths[0][i - 1];
        }
    }
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (grid[i][j] == '#') {
                paths[i][j] = 0;
            } else {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                paths[i][j] %= 1000000007;
            }
        }
    }
    cout << paths[x - 1][y - 1] << '\n';
    return 0;
}