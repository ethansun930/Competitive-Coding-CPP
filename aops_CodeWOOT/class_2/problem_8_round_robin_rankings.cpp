#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    vector<int> n(T);
    vector<int> k(T);
    int max_n = 0;
    for (int i = 0; i < T; i++) {
        cin >> n[i] >> k[i];
        max_n = max(max_n, n[i]);
    }
    int max_exp = (max_n * (max_n - 1))/2;
    vector<long long> power_of_two(1 + max_exp, 1);
    for (int i = 1; i <= max_exp; i++) {
        power_of_two[i] = (2 * power_of_two[i - 1])%MOD;
    }
    vector<vector<long long>> C(max_n + 1, vector<long long> (max_n + 1, 0));
    for (int i = 0; i <= max_n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
        }
    }
    vector<long long> t(max_n + 1);
    for (int i = 0; i <= max_n; i++) {
        t[i] = power_of_two[(i * (i - 1))/2];
    }
    vector<long long> s(max_n + 1, 0);
    for (int i = 1; i <= max_n; i++) {
        s[i] = t[i];
        for (int j = 1; j < i; j++) {
            s[i] -= ((C[i][j] * s[j])%MOD * t[i - j])%MOD;
            s[i] %= MOD;
        }
        s[i] = (s[i] + MOD)%MOD;
    }
    vector<vector<long long>> f(max_n + 1, vector<long long>(max_n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= max_n; i++) {
        for (int j = 1; j <= max_n; j++) {
            // when k > i - j + 1, i - k < j - 1, so f[i - k][j - 1] = 0, and there is no purpose of adding it.
            for (int k = 1; k <= (i - j + 1); k++) {
                f[i][j] += ((C[i][k] * s[k])%MOD * f[i - k][j - 1]);
                f[i][j] %= MOD;
            }
            f[i][j] = (f[i][j] + MOD)%MOD;
        }
    }
    for (int i = 0; i < T; i++) {
        cout << f[n[i]][k[i]] << '\n';
    }
    return 0;
}