#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        maximum = max(maximum, a[i]);
    }
    if (maximum == 0) {
        cout << 0 << '\n';
        return;
    }
    for (int i = maximum; i <= sum; i++) {
        if (sum % i != 0) {
            continue;
        }
        int curr_sum = 0;
        for (int j = 0; j < N; j++) {
            if (curr_sum == i) {
                curr_sum = 0;
            }
            if (curr_sum > i) {
                break;
            }
            curr_sum += a[j];
        }
        if (curr_sum == i) {
            cout << N - sum / i << '\n';
            break;
        }
    }
}
/*
for every a, you check if the first few elements can make a, and then if they
can't, the answer is no, if they can, check if the later elements can, and so on
*/
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}