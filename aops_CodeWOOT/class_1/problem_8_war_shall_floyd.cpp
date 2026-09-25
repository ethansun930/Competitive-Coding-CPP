#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long A;
            cin >> A;
            if (A == 1000000000000000000) {
                a[i][j] = -1;
            }
            else {
                a[i][j] = static_cast<int>(A);
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (a[i][k] == -1) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (a[k][j] != -1) {
                    if (a[i][j] == -1) {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                    else {
                        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i][0] == -1) {
                cout << "1000000000000000000";
            }
        else {
            cout << a[i][0];
        }
        for (int j = 1; j < N; j++) {
            if (a[i][j] == -1) {
                cout << ' ' << "1000000000000000000";
            }
            else {
                cout << ' ' << a[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}