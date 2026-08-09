#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<array<long long, 3>> times;
bool possible(long long sum, long long tc, long long tm) {
    /*
    we want pos int x & y, such that:
        x + y = sum, so
        y = sum - x, and
        0 <= x <= tc - 1, and
        0 <= sum - x < tm, so
        -tm < x - sum <= 0,
        sum - tm + 1 <= x <= sum,
        _____________________________________________
        max(0, sum - tm + 1) <= x <= min(sum, tc - 1)
        _____________________________________________
        for all i from 1 to N:
            ai(tc - x) + bi(tm - y) <= ci, so
            ai * tc + bi * tm - ai * x - bi * y <= ci,
            let l = ai * tc + bi * tm - ci.
            l - ai * x - bi * sum + bi * x <= 0
            l - bi * sum <= (ai - bi) * x,
    */
    long long bottom = max(0LL, sum - tm + 1);
    long long top = min(sum, tc - 1);
    if (bottom > top) {
        // cout << "failed with bottom > top with middle, ai, bi, ci: " << sum
        // << ai << bi << ci << '\n';
        return false;
    }
    for (int i = 0; i < N; i++) {
        long long ai = times[i][0];
        long long bi = times[i][1];
        long long ci = times[i][2];
        long long compare = ai * tc + bi * tm - ci - bi * sum;
        if (ai == bi) {
            if (compare > 0) {
                // cout << "failed with ai = bi and compare > 0 with middle, ai,
                // bi, ci:" << sum << ai << bi << ci << '\n';
                return false;
            }
        } else if (ai > bi) {
            /*
            -d < compare < 0: 
                compare = -3, 
                d = 5,
                bound want be 0.
                current bound = 0.
            compare < -d < 0:
                compare = -5
                d = 3
                bound want be -1.
                current bound = -1
            0 < compare < d:
                compare = 3
                d = 5
                bound want be 1
                current bound = 0
            0 < d < compare:
                compare = 5
                d = 3
                bound want be 2
                current bound = 1
            */
            long long d = ai - bi;  // d > 0
            long long bound = compare / d;
            if (compare > 0 && compare % d != 0) bound++;
            bottom = max(bottom, bound);
        } else {
            long long d = ai - bi;  // d < 0
            long long bound = compare / d;
            if (compare > 0 && compare % d != 0) bound--;
            top = min(top, bound);
        }
        // cout << "worked: " << sum << ' ' << ai << ' ' << bi << ' ' << ci << '
        // ' << top << ' ' << bottom << ' ' << compare << '\n';
        if (bottom > top) {
            // cout << "failed with bottom > top with middle, ai, bi, ci: " <<
            // sum << ai << bi << ci << '\n';
            return false;
        }
    }
    // cout << "this m worked: " << sum << '\n';
    return true;
}
int main() {
    int T;
    cin >> T;
    vector<long long> answers;
    for (int z = 0; z < T; z++) {
        long long tc;
        long long tm;
        times.clear();
        cin >> N;
        cin >> tc;
        cin >> tm;
        for (int i = 0; i < N; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            times.push_back({a, b, c});
        }
        long long left = 0;
        long long right = tc + tm - 1;
        while (left < right) {
            long long middle = (left + right) / 2;
            // cout << middle << "middle" << '\n';
            if (possible(middle, tc, tm)) {
                right = middle;
                // cout << right << "right" << '\n';
            } else {
                left = middle + 1;
                // cout << left << "left" << '\n';
            }
        }
        answers.push_back(right);
        // cout << "current round finished" << '\n';
    }
    for (const long long& ans : answers) {
        cout << ans << '\n';
    }
    return 0;
}