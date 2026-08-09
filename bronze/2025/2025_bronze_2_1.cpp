#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, U;
    cin >> N >> U;
    vector<vector<int>> canvas(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < N; j++) {
            if (x[j] == '#') {
                canvas[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int count = canvas[i][j] + canvas[N - i - 1][j] +
                        canvas[i][N - j - 1] + canvas[N - i - 1][N - j - 1];
            if (count <= 2) {
                ans += count;
            } else {
                ans += 4 - count;
            }
        }
    }
    cout << ans << '\n';
    while (U--) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        int count = canvas[i][j] + canvas[N - i - 1][j] + canvas[i][N - j - 1] +
                    canvas[N - i - 1][N - j - 1];
        if (count <= 2) {
            ans -= count;
        } else {
            ans -= 4 - count;
        }
        if (canvas[i][j] == 0) {
            canvas[i][j] = 1;
            count++;
        } else {
            canvas[i][j] = 0;
            count--;
        }
        if (count <= 2) {
            ans += count;
        } else {
            ans += 4 - count;
        }
        cout << ans << '\n';
    }
    return 0;
}
