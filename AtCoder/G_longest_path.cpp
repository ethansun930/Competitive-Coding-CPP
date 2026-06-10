#include <iostream>
#include <vector>
using namespace std;

int find_max(int i, vector<int>& max_path, vector<vector<int>>& connected) {
    if (max_path[i] != -1) {
        return max_path[i];
    }
    int ans = 0;
    int N = connected.size();
    for (int j : connected[i]) {
        ans = max(ans, find_max(j, max_path, connected) + 1);
    }
    max_path[i] = ans;
    return ans;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> connected(N);
    for (int i = 0; i < M; i++) {
        int x;
        int y;
        cin >> x >> y;
        x--;
        y--;
        connected[x].push_back(y);
    }
    vector<int> max_path(N, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, find_max(i, max_path, connected));
    }
    cout << ans << '\n';
    return 0;
}