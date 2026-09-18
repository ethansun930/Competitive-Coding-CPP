// help form chatgpt
#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

long long f_div(long long a, long long b) {
    long long ans = a / b;
    if (a < 0 && a % b != 0) {
        ans--;
    }
    return ans;
}
bool check(long long b, vector<pair<long long, long long>>& corners,
           vector<long long>& s) {
    vector<long long> cap;
    for (int i = 0; i < corners.size(); i++) {
        cap.push_back(f_div((corners[i].second - b), corners[i].first));
    }
    sort(cap.begin(), cap.end());
    for (int i = 0; i < cap.size(); i++) {
        if (s[i] > cap[i]) {
            return false;
        }
    }
    return true;
}
void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<pair<long long, long long>> pos(N);
    vector<pair<long long, long long>> neg(N);
    vector<long long> lefts(2 * N);
    for (int i = 0; i < N; i++) {
        long long y1, y2, x2;
        cin >> y1 >> y2 >> x2;
        pos[i] = {x2, y1};
        neg[i] = {x2, -y2};
        lefts[2 * i] = y1;
        lefts[2 * i + 1] = y2;
    }
    sort(lefts.begin(), lefts.end());
    vector<long long> pos_s;
    vector<long long> neg_s;
    for (int i = 0; i < 4 * N; i++) {
        long long s;
        cin >> s;
        if (s > 0) {
            pos_s.push_back(s);
        } else {
            neg_s.push_back(-s);
        }
    }
    sort(pos_s.begin(), pos_s.end());
    sort(neg_s.begin(), neg_s.end());
    if (pos_s.size() < N || neg_s.size() < N) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < neg_s.size() - N; i++) {
        neg.push_back({X, -lefts[i]});
    }
    for (int i = neg_s.size() - N; i < 2 * N; i++) {
        pos.push_back({X, lefts[i]});
    }
    long long min_y = LLONG_MAX;
    long long max_x = LLONG_MIN;
    for (int i = 0; i < pos.size(); i++) {
        min_y = min(min_y, pos[i].second);
        max_x = max(max_x, pos[i].first);
    }
    long long l = min_y - pos_s.back() * max_x;
    long long r = min_y;
    while (l < r) {
        long long m = f_div(l + r, 2);
        if (check(m, pos, pos_s)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    long long lower = l - 1;
    min_y = LLONG_MAX;
    max_x = LLONG_MIN;
    for (int i = 0; i < neg.size(); i++) {
        min_y = min(min_y, neg[i].second);
        max_x = max(max_x, neg[i].first);
    }
    l = min_y - neg_s.back() * max_x;
    r = min_y;
    while (l < r) {
        long long m = f_div(l + r, 2);
        if (check(m, neg, neg_s)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << -(lower + l - 1) << '\n';
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}