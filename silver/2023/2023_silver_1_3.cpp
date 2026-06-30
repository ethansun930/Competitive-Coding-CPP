#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int T = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        T += a[i];
    }
    string ans = "";
    int pos = 0;
    while (true) {
        while (pos < N && (a[pos] > 0)) {
            a[pos]--;
            pos++;
            ans += 'R';
        }
        if (pos == 0) {
            break;
        }
        while (pos > 0 && (pos == N || (a[pos - 1] > 1 || a[pos] == 0))) {
            a[pos - 1]--;
            pos--;
            ans += 'L';
        }
    }
    cout << ans << '\n';
    return 0;
}
