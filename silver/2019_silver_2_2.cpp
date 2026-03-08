#include<iostream>
// #include<cstdio>
using namespace std;
static int change[1002][1002];
static int values[1001][1001];
int main() {
    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            change[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        change[x1][y1]++;
        change[x2][y2]++;
        change[x1][y2]--;
        change[x2][y1]--;
    }
    values[0][0] = change[0][0];
    for (int i = 1; i < 1001; i++) {
        values[i][0] = values[i-1][0] + change[i][0];
        values[0][i] = values[0][i-1] + change[0][i];
    }
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            values[i][j] = values[i-1][j] + values[i][j-1] - values[i-1][j-1] + change[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (values[i][j] == K) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}