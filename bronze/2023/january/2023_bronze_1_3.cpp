#include <climits>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        string moo;
        cin >> moo;
        if (moo.size() <= 2) {
            cout << -1 << '\n';
            continue;
        }
        int ans = INT_MAX;
        int cost[8] = {1, 2, -1, -1, 0, 1, -1, -1};
        for (int i = 0; i < moo.size() - 2; i++) {
            int map = 0;
            if (moo[i + 2] == 'M') {
                map++;
            }
            if (moo[i + 1] == 'M') {
                map += 2;
            }
            if (moo[i] == 'M') {
                map += 4;
            }
            if (cost[map] != -1) {
                ans = min(ans, cost[map]);
            }
        }
        if (ans == INT_MAX) {
            cout << -1 << '\n';
            continue;
        }
        ans += moo.length() - 3;
        cout << ans << '\n';
    }
    return 0;
}