#include<iostream>
#include<vector>
#define NMAX 1001
using namespace std;
int A[NMAX][NMAX];
int dir[5] = {0, 1, 0, -1, 0};

bool is_valid(int m, int n) {
    if (m < 0 || n < 0 || m >= NMAX || n >= NMAX) {
        return false;
    }
    return true;
}

bool is_comfortable(int x, int y) {
    int count = 0;
    if (A[x][y] == 0) {
        return false;
    }
    for (int d = 0; d < 4; d++) {
        int m = x + dir[d];
        int n = y + dir[d+1];
        if (is_valid(m, n) && A[m][n] == 1) {
            count++;
        }
    }
    return count == 3;
}

int main() {
    int N;
    cin >> N;
    int x;
    int y;
    int ans = 0;
    vector<int> answers;
    for (int i = 0; i < N; i++) {
        cin >> x;
        cin >> y;
        for (int j = 0; j < 4; j++) {
            int m = x + dir[j];
            int n = y + dir[j+1];
            if (!is_valid(m, n)) {
                continue;
            }
            if (is_comfortable(m, n)) {
                // cout << "delete: m: [" << m << "] n: [" << n << "] count: [" << count << "]\n";
                ans--;
            }
        }
        A[x][y] = 1;
        for (int j = 0; j < 4; j++) {
            int m = x + dir[j];
            int n = y + dir[j+1];
            if (!is_valid(m, n)) {
                continue;
            }
            if (is_comfortable(m, n)) {
                // cout << "add neighbor: m: [" << m << "] n: [" << n << "] count: [" << count << "]\n";
                ans++;
            }
        }
        if (is_comfortable(x, y)) {
            // cout << "add self: x: [" << x << "] y: [" << y << "] count: [" << count << "]\n";
            ans++;
        }
        // cout << ans << "\n";
        answers.push_back(ans);
    }
    for (const int& x : answers) {
        cout << x << "\n";
    }
    return 0;
}