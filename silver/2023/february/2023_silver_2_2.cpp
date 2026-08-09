#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct coordinate {
    long long t, x, y;
    bool operator<(const coordinate& other) const { return t < other.t; }
};
bool reachable(coordinate& a, coordinate& b) {
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    long long t = a.t - b.t;
    if (x * x + y * y > t * t) {
        return false;
    }
    return true;
}
int main() {
    long long G, N;
    cin >> G >> N;
    vector<coordinate> grazing(G);
    for (long long i = 0; i < G; i++) {
        cin >> grazing[i].x >> grazing[i].y >> grazing[i].t;
    }
    sort(grazing.begin(), grazing.end());
    vector<coordinate> alibi(N);
    for (long long i = 0; i < N; i++) {
        cin >> alibi[i].x >> alibi[i].y >> alibi[i].t;
    }
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        long long l = 0;
        long long r = G;
        while (l < r) {
            long long m = (l + r) / 2;
            if (grazing[m].t > alibi[i].t) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l == 0) {
            if (!reachable(grazing[0], alibi[i])) {
                ans++;
                // cout << i << ' ';
            }
        } else {
            l--;
            if (l != G - 1) {
                if (!reachable(grazing[l], alibi[i]) ||
                    !reachable(grazing[l + 1], alibi[i])) {
                    ans++;
                    // cout << i << ' ';
                }
            } else {
                if (!reachable(grazing[l], alibi[i])) {
                    ans++;
                    // cout << i << ' ';
                }
            }
        }
    }
    cout << ans << '\n';
}