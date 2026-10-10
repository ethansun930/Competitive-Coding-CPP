#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int T, N;
    cin >> T >> N;
    string S;
    cin >> S;
    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        s[i] = S[i] - 'A';
    }
    if (T == 0) {
        vector<int> increase(N, 1);
        for (int i = 1; i < N; i++) {
            if (s[i - 1] <= s[i]) {
                increase[i] = increase[i - 1] + 1;
            }
        }
        vector<int> decrease(N, 0);
        for (int i = N - 2; i >= 0; i--) {
            if (s[i + 1] <= s[i]) {
                decrease[i] = decrease[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, increase[i] + decrease[i]);
        }
        cout << ans << '\n';
    }
    else {
        int dp_in[26] = {0};
        vector<int> increase(N, 1);
        for (int i = 0; i < N; i++) {
            dp_in[s[i]]++;
            for (int j = 0; j < s[i]; j++) {
                dp_in[s[i]] = max(dp_in[s[i]], dp_in[j] + 1);
            }
            increase[i] = dp_in[s[i]];
        }
        int dp_de[26] = {0};
        vector<int> decrease(N, 1);
        for (int i = N - 1; i >= 0; i--) {
            dp_de[s[i]]++;
            for (int j = 0; j < s[i]; j++) {
                dp_de[s[i]] = max(dp_de[s[i]], dp_de[j] + 1);
            }
            decrease[i] = dp_de[s[i]];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, increase[i] + decrease[i] - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}