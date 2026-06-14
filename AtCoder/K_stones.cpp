#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<bool> dp(K + 1);
    dp[0] = false;
    for (int i = 1; i <= K; i++) {
        dp[i] = false;
        for (int j = 0; j < N; j++) {
            if (i >= a[j]) {
                dp[i] = (dp[i] || (!dp[i - a[j]]));
            }
        }
    }
    if (dp[K] == true) {
        cout << "First" << '\n';
    } else {
        cout << "Second" << '\n';
    }
    return 0;
}