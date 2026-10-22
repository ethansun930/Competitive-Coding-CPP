#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int d[5] = {0, 1, 0, -1, 0};
struct State {
    int i, j, k, moves;
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> M(N, vector<int>(N));
    pair<int, int> S;
    pair<int, int> E;
    for (int i = 0; i < N; i++) {
        string m;
        cin >> m;
        for (int j = 0; j < N; j++) {
            if (m[j] == '.') {
                M[i][j] = 0;
            }
            else if (m[j] == 'C') {
                M[i][j] = 1;
            }
            else if (m[j] == '#') {
                M[i][j] = 2;
            }
            else if (m[j] == 'S') {
                M[i][j] = 3;
                S.first = i;
                S.second = j;
            }
            else {
                M[i][j] = 3;
                E.first = i;
                E.second = j;
            }
        }
    }
    vector<vector<vector<int>>> min_moves(N, vector<vector<int>>(N, vector<int>(K + 1, INT_MAX)));
    min_moves[S.first][S.second][0] = 0;
    queue<State> q;
    q.push({S.first, S.second, 0, 0});
    while (!q.empty()) {
        State state = q.front();
        q.pop();
        if (state.moves > min_moves[state.i][state.j][state.k]) {
            continue;
        }
        for (int t = 0; t < 4; t++) {
            if (state.i + d[t] < 0 || state.i + d[t] >= N || state.j + d[t + 1] < 0 || state.j + d[t + 1] >= N) {
                continue;
            }
            else if (M[state.i + d[t]][state.j + d[t + 1]] == 2) {
                continue;
            }
            else if (M[state.i + d[t]][state.j + d[t + 1]] == 1) {
                if (state.k == K) {
                    continue;
                }
                if (state.moves + 1 >= min_moves[state.i + d[t]][state.j + d[t + 1]][state.k + 1]) {
                    continue;
                }
                min_moves[state.i + d[t]][state.j + d[t + 1]][state.k + 1] = state.moves + 1;
                q.push({state.i + d[t], state.j + d[t + 1], state.k + 1, state.moves + 1});
            }
            else {
                if (state.moves + 1 >= min_moves[state.i + d[t]][state.j + d[t + 1]][state.k]) {
                    continue;
                }
                min_moves[state.i + d[t]][state.j + d[t + 1]][state.k] = state.moves + 1;
                q.push({state.i + d[t], state.j + d[t + 1], state.k, state.moves + 1});
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, min_moves[E.first][E.second][i]);
        cout << ans << '\n';
    }
    return 0;
}