#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
vector<int> forward(vector<int>& old_cow) {
    vector<int> cow = old_cow;
    if (cow[2] == 0) {
        cow[1]++;
    } else if (cow[2] == 1) {
        cow[0]++;
    } else if (cow[2] == 2) {
        cow[1]--;
    } else {
        cow[0]--;
    }
    return cow;
}
int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> barn(N + 2, vector<int>(N + 2, 1));
    for (int i = N - 1; i >= 0; i--) {
        string x;
        cin >> x;
        for (int j = 0; j < N; j++) {
            if (x[j] == 'E') {
                barn[i + 1][j + 1] = 0;
            }
        }
    }
    // vector<int> comes in as {xcoor1, ycoor1, xcoor2, ycoor2, dir, steps}
    // note that with dir, we find dir1 = dir and dir2 = (dir + 1)%4
    // up = 0, right = 1, down = 2, left = 3
    queue<vector<int>> q;
    bool visited[22][22][22][22][4] = {false};
    q.push({1, 1, 1, 1, 0, 0});
    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();
        // cout << node[0] << node[1] << node[2] << node[3] << node[4] <<
        // node[5]
        //  << '\n';
        if (node[0] == N && node[1] == N && node[2] == N && node[3] == N) {
            // cout << '\t' << "found" << '\n';
            cout << node[5] << '\n';
            return 0;
        }
        if (visited[node[0]][node[1]][node[2]][node[3]][node[4]]) {
            // cout << '\t' << "not worked" << '\n';
            continue;
        }
        visited[node[0]][node[1]][node[2]][node[3]][node[4]] = true;
        vector<int> cow1 = {node[0], node[1], node[4]};
        vector<int> cow2 = {node[2], node[3], (node[4] + 1) % 4};
        vector<int> forward1 = forward(cow1);
        vector<int> forward2 = forward(cow2);
        if ((cow1[0] == N && cow1[1] == N) ||
            barn[forward1[0]][forward1[1]] == 1) {
            forward1 = cow1;
        }
        if ((cow2[0] == N && cow2[1] == N) ||
            barn[forward2[0]][forward2[1]] == 1) {
            forward2 = cow2;
        }
        q.push({forward1[0], forward1[1], forward2[0], forward2[1], node[4],
                node[5] + 1});
        // cout << '\t' << forward1[0] << forward1[1] << forward2[0] <<
        // forward2[1]
        //  << node[4] << node[5] + 1 << '\n';
        q.push({node[0], node[1], node[2], node[3], (node[4] + 1) % 4,
                node[5] + 1});
        // cout << '\t' << node[0] << node[1] << node[2] << node[3]
        //      << (node[4] + 1) % 4 << node[5] + 1 << '\n';
        q.push({node[0], node[1], node[2], node[3], (node[4] + 3) % 4,
                node[5] + 1});
        // cout << '\t' << node[0] << node[1] << node[2] << node[3]
        //      << (node[4] + 3) % 4 << node[5] + 1 << '\n';
    }
    return 0;
}