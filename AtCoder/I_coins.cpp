#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<double> prev(N + 1, 0);
    prev[0] = 1;
    vector<double> curr(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        curr[0] = prev[0] * (1 - p[i - 1]);
        for (int j = 1; j < i; j++) {
            curr[j] = (prev[j] * (1 - p[i - 1])) + (prev[j - 1] * p[i - 1]);
        }
        curr[i] = prev[i - 1] * p[i - 1];
        prev = curr;
    }
    double ans = 0;
    for (int i = (N - 1) / 2 + 1; i <= N; i++) {
        ans += prev[i];
    }
    cout << setprecision(100) << ans << '\n';
    return 0;
}