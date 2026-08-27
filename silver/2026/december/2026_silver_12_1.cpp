#include <algorithm>
#include <iostream>
using namespace std;

void solve1(long long c, long long t) {
    if (c == t) {
        cout << t << '\n';
        return;
    }
    if (2 * c > t) {
        cout << c << '\n';
        return;
    }
    long long pos = c;
    long long time = 2 * c - 1;
    if (c == 0) {
        time = 1;
    }
    while (time < t) {
        if (pos == 0) {
            time++;
            pos = time / 2;
        } else {
            long long amount = min(pos, t - time);
            time += amount;
            pos -= amount;
        }
    }
    cout << pos << '\n';
}
void solve2(long long x, long long t) {
    if (2 * x > t) {
        cout << x << '\n';
        return;
    }
    long long pos = x;
    long long time = t;
    while (2 * pos <= time) {
        if (pos == time / 2) {
            pos = 0;
            time--;
        } else {
            long long amount = (time - 2 * pos) / 3;
            if (amount == 0) {
                amount = 1;
            }
            time -= amount;
            pos += amount;
        }
    }
    cout << pos << '\n';
}
int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        long long type;
        cin >> type;
        long long c, t;
        cin >> c >> t;
        if (type == 1) {
            solve1(c, t);
        } else {
            solve2(c, t);
        }
    }
    return 0;
}