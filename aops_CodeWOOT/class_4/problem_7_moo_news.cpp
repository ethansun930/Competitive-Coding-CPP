#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool check(vector<int> m, vector<int> prefix, int L, int R) {
    int N = m.size();
    vector<bool> dp(N + 1, false);
    dp[0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (prefix[i] - prefix[j] > R) {
                break;
            }
            if (prefix[i] - prefix[j] < L) {
                continue;
            }
            if (dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];
}
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + m[i - 1];
    }
    int R = A;
    int ans = INT_MAX;
    for (int L = A; L <= B; L++) {
        while (R <= B && !check(m, prefix, L, R)) {
            R++;
        }
        if (R == B + 1) {
            break;
        }
        ans = min(ans, R - L);
    }
    cout << ans << '\n';
    return 0;
}