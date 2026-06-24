#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
int N;
set<pair<int, int>> illuminated;
set<pair<int, int>> visited;
bool has_visited_neighbor(pair<int, int> location) {
    if (visited.find(make_pair(location.first, location.second + 1)) !=
        visited.end()) {
        return true;
    }
    if (visited.find(make_pair(location.first, location.second - 1)) !=
        visited.end()) {
        return true;
    }
    if (visited.find(make_pair(location.first + 1, location.second)) !=
        visited.end()) {
        return true;
    }
    if (visited.find(make_pair(location.first - 1, location.second)) !=
        visited.end()) {
        return true;
    }
    return false;
}

void DFS(pair<int, int> location,
         vector<vector<vector<pair<int, int>>>>& switches) {
    if (illuminated.find(location) == illuminated.end()) {
        return;
    }
    if (visited.find(location) != visited.end()) {
        return;
    }
    visited.insert(location);
    for (const auto& curr : switches[location.first][location.second]) {
        illuminated.insert(curr);
        if (has_visited_neighbor(curr)) {
            DFS(curr, switches);
        }
    }
    location.first++;
    DFS(location, switches);
    location.first -= 2;
    DFS(location, switches);
    location.first++;
    location.second++;
    DFS(location, switches);
    location.second -= 2;
    DFS(location, switches);
    return;
}
int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int M;
    cin >> N >> M;
    vector<vector<vector<pair<int, int>>>> switches(
        N, vector<vector<pair<int, int>>>(N));
    illuminated.insert(make_pair(0, 0));
    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--;
        y--;
        a--;
        b--;
        switches[x][y].push_back(make_pair(a, b));
    }
    DFS(make_pair(0, 0), switches);
    cout << illuminated.size() << '\n';
    return 0;
}