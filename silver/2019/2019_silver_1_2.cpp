#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& cream, vector<vector<bool>>& visited, int i,
         int j, int& area, int& perimeter) {
    if (i < 0 || i >= cream.size() || j < 0 || j >= cream.size()) {
        perimeter++;
        return;
    }
    if (visited[i][j]) {
        return;
    }
    if (cream[i][j] == 0) {
        perimeter++;
        return;
    } else {
        area++;
    }
    visited[i][j] = true;
    int d[5] = {1, 0, -1, 0, 1};
    for (int t = 0; t < 4; t++) {
        dfs(cream, visited, i + d[t], j + d[t + 1], area, perimeter);
    }
    return;
}
int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> cream(N, vector<int>(N, 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            if (x == '.') {
                cream[i][j] = 0;
            }
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int area = 0;
    int perimeter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cream[i][j] == 1 && !visited[i][j]) {
                int new_area = 0;
                int new_perimeter = 0;
                dfs(cream, visited, i, j, new_area, new_perimeter);
                if (new_area > area) {
                    area = new_area;
                    perimeter = new_perimeter;
                } else if (new_area == area) {
                    perimeter = min(perimeter, new_perimeter);
                }
            }
        }
    }
    cout << area << ' ' << perimeter << '\n';
    return 0;
}