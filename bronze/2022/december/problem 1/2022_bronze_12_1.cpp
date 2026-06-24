#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    long long ans = 0;
    long long tuition = 0;
    for (int i = 0; i < N; i++) {
        long long new_ans = c[i] * (N - i);
        if (ans < new_ans) {
            ans = new_ans;
            tuition = c[i];
        } else if (ans == new_ans) {
            tuition = min(tuition, c[i]);
        }
    }
    cout << ans << ' ' << tuition << '\n';
    return 0;
}