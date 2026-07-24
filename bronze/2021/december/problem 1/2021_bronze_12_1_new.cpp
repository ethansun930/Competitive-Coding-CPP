#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string x;
    cin >> x;
    vector<int> breeds(N, 0);
    for (int i = 0; i < N; i++) {
        if (x[i] == 'H') {
            breeds[i] = 1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long l = 0;
        long long r = 0;
        if (i > 0 && (breeds[i - 1] != breeds[i])) {
            l++;
            for (int j = i - 2; j >= 0; j--) {
                if (x[j] == x[i - 1]) {
                    l++;
                } else {
                    break;
                }
            }
        }
        if (i < N - 1 && (x[i + 1] != x[i])) {
            r++;
            for (int j = i + 2; j < N; j++) {
                if (x[j] == x[i + 1]) {
                    r++;
                } else {
                    break;
                }
            }
                }
        ans += (l * r + max(0LL, l - 1) + max(0LL, r - 1));
    }
    cout << ans << '\n';
    return 0;
}