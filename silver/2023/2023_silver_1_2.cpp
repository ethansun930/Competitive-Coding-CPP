#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void update_path(vector<vector<int>>& directions, vector<vector<int>>& dp,
                 long long& ans, int x, int y, int adder) {
    int N = directions.size() - 1;
    int new_x = x;
    int new_y = y;
    while (new_x < N && new_y < N) {
        dp[new_x][new_y] += adder;
        if (directions[new_x][new_y] == 0) {
            new_y++;
        } else {
            new_x++;
        }
    }
    ans += (adder * directions[new_x][new_y]);
}
void flip_dir(vector<vector<int>>& directions, vector<vector<int>>& dp,
              long long& ans, int x, int y) {
    int new_x = x;
    int new_y = y;
    if (directions[x][y] == 0) {
        new_y++;
    } else {
        new_x++;
    }
    update_path(directions, dp, ans, new_x, new_y, -dp[x][y]);
    directions[x][y] = 1 - directions[x][y];
    new_x = x;
    new_y = y;
    if (directions[x][y] == 0) {
        new_y++;
    } else {
        new_x++;
    }
    update_path(directions, dp, ans, new_x, new_y, dp[x][y]);
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> directions(N + 1, vector<int>(N + 1, 1));
    for (int i = 0; i < N; i++) {
        string x;
        int c;
        cin >> x >> c;
        directions[i][N] = c;
        for (int j = 0; j < N; j++) {
            if (x[j] == 'R') {
                directions[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> directions[N][i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1));
    for (int i = 1; i < N; i++) {
        if (directions[i - 1][0] == 1) {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        if (directions[0][i - 1] == 0) {
            dp[0][i] = dp[0][i - 1] + 1;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (directions[i - 1][j] == 1) {
                dp[i][j] += dp[i - 1][j];
            }
            if (directions[i][j - 1] == 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (directions[i][N - 1] == 0) {
            ans += (dp[i][N - 1] * directions[i][N]);
        }
        if (directions[N - 1][i] == 1) {
            ans += (dp[N - 1][i] * directions[N][i]);
        }
    }
    cout << ans << '\n';
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        flip_dir(directions, dp, ans, x, y);
        cout << ans << '\n';
    }
    return 0;
}