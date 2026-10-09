#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int d[5] = {1, 0, -1, 0, 1};
void press(vector<vector<int>>& C, int i, int j) {
    C[i][j] = 1 - C[i][j];
    int N = C.size();
    for (int t = 0; t < 4; t++) {
        if (i + d[t] >= 0 && i + d[t] < N && j + d[t + 1] >= 0 && j + d[t + 1] < N) {
            C[i + d[t]][j + d[t + 1]] = 1 - C[i + d[t]][j + d[t + 1]];
        }
    }
}
int main() {
    int N;
    cin >> N;
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            C[i][j] = s[j] - '0';
        }
    }
    int ans = INT_MAX;
    for (int t = 0; t < (1 << N); t++) {
        int curr = 0;
        vector<vector<int>> new_C = C;
        for (int i = 0; i < N; i++) {
            if ((t & (1 << i)) != 0) {
                press(new_C, 0, i);
                curr++;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                if (new_C[i][j] == 1) {
                    curr++;
                    press(new_C, i + 1, j);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (new_C[N - 1][i] == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans, curr);
        }
    }
    cout << ans << '\n';
    return 0;
}