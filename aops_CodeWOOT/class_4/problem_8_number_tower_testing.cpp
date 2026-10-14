/* very horrible brute force search, only passes one test case.*/
#include<iostream>
#include<vector>
using namespace std;

int d[5] = {0, 1, 0, -1, 0};
long long power (int n) {
    if (n == 0) {
        return 1;
    }
    else if (n%2 == 0) {
        return power(n/2) * power(n/2);
    }
    else {
        return power(n/2) * power(n/2) * 3;
    }
}
int main() {
    int H, V, T;
    cin >> H >> V >> T;
    int ans = 0;
    for (long long t = 0; t < power(H * V); t++) {
        long long new_t = t;
        vector<vector<int>> a(H, vector<int>(V));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < V; j++) {
                a[i][j] = new_t%3;
                a[i][j]++;
                new_t /= 3;
            }
        }
        bool ok = true;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < V; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    if ((i + d[k]) < H && (i + d[k]) >= 0) {
                        if (a[i + d[k]][(j + d[k + 1] + V)%V] == a[i][j]) {
                            sum++;
                        }
                    }
                }
                if (sum != a[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    if (T == 0) {
        cout << ans << '\n';
    }
    else {
        cout << ans/H << '\n';
    }
    return 0;
}