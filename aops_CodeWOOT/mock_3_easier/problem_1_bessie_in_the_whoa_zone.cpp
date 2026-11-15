#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct State {
    int x, y, grav;
    long long moves;
};
int main() {
    int N, K, C, W;
    cin >> N >> K >> C >> W;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        grid[i][0] = 1;
        grid[0][i] = 1;
        grid[i][N - 1] = 1;
        grid[N - 1][i] = 1;
    }
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        grid[c][r] = 1;
    }
    vector<vector<vector<int>>> d(N, vector<vector<int>>(N, vector<int>(4, 0)));
    for (int i = 1; i < N - 1; i++) {
        int last_hit = 0;
        for (int j = 1; j < N - 1; j++) {
            if (grid[j][i] == 1) {
                last_hit = j;
            }
            d[j][i][3] = j - last_hit - 1;
        }
        last_hit = N - 1;
        for (int j = N - 2; j > 0; j--) {
            if (grid[j][i] == 1) {
                last_hit = j;
            }
            d[j][i][1] = last_hit - j - 1;
        }
        last_hit = 0;
        for (int j = 1; j < N - 1; j++) {
            if (grid[i][j] == 1) {
                last_hit = j;
            }
            d[i][j][0] = j - last_hit - 1;
        }
        last_hit = N - 1;
        for (int j = N - 2; j > 0; j--) {
            if (grid[i][j] == 1) {
                last_hit = j;
            }
            d[i][j][2] = last_hit - j - 1;
        }
    }
    vector<vector<vector<long long>>> distance(N, vector<vector<long long>>(N, vector<long long>(4, LLONG_MAX)));
    distance[1][1][0] = 0;
    queue<State> q;
    q.push({1, 1, 0, 0});
    while (!q.empty()) {
        State state = q.front();
        q.pop();
        if (state.x == N - 2 && state.y == N - 2) {
            continue;
        }
        if (distance[state.x][state.y][state.grav] < state.moves) {
            continue;
        }
        int new_grav = (state.grav + 1)%4;
        long long dis = d[state.x][state.y][new_grav];
        int new_x = state.x + dis * dx[new_grav];
        int new_y = state.y + dis * dy[new_grav];
        if (distance[new_x][new_y][new_grav] > state.moves + W + dis * dis) {
            distance[new_x][new_y][new_grav] = state.moves + W + dis * dis;
            q.push({new_x, new_y, new_grav, distance[new_x][new_y][new_grav]});
        }
        new_grav = (state.grav + 3)%4;
        dis = d[state.x][state.y][new_grav];
        new_x = state.x + dis * dx[new_grav];
        new_y = state.y + dis * dy[new_grav];
        if (distance[new_x][new_y][new_grav] > state.moves + C + dis * dis) {
            distance[new_x][new_y][new_grav] = state.moves + C + dis * dis;
            q.push({new_x, new_y, new_grav, distance[new_x][new_y][new_grav]});
        }
    }
    cout << min(min(distance[N - 2][N - 2][0], distance[N - 2][N - 2][1]), min(distance[N - 2][N - 2][2], distance[N - 2][N - 2][3])) << '\n';
    return 0;
}