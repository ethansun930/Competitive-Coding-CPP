#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> multiply(vector<vector<long long>>& a,
                                   vector<vector<long long>>& b) {
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 1000000007;
            }
        }
    }
    return c;
}
vector<vector<long long>> find_amount(vector<vector<long long>>& a,
                                      long long k) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0LL));
    for (int i = 0; i < n; i++) {
        result[i][i] = 1LL;
    }

    while (k > 0) {
        if (k % 2 == 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        k /= 2;
    }
    return result;
}
int main() {
    long long N, K;
    cin >> N >> K;
    vector<vector<long long>> a(N, vector<long long>(N, 0LL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    if (K == 0) {
        cout << N % 1000000007 << '\n';
        return 0;
    }
    vector<vector<long long>> ans = find_amount(a, K);
    long long count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            count += ans[i][j];
            count %= 1000000007;
        }
    }
    cout << count << '\n';
    return 0;
}