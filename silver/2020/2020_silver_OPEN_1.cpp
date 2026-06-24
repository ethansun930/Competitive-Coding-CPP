#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    long long start;
    long long end;
    bool operator<(const Interval& other) const { return start < other.start; }
};
bool worked(long long D, vector<Interval>& grass, int N) {
    long long last_cow = grass[0].start;
    int interval_idx = 0;
    for (int i = 1; i < N; i++) {
        long long next_cow = last_cow + D;
        while (interval_idx < grass.size() &&
               grass[interval_idx].end < next_cow) {
            interval_idx++;
        }
        if (interval_idx == grass.size()) {
            return false;
        }
        last_cow = max(next_cow, grass[interval_idx].start);
    }
    return true;
}
int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<Interval> grass(M);
    for (int i = 0; i < M; i++) {
        cin >> grass[i].start >> grass[i].end;
        grass[i].start--;
        grass[i].end--;
    }
    sort(grass.begin(), grass.end());
    long long left = 1;
    long long right = grass[grass.size() - 1].end - grass[0].start + 1;
    while (left < right) {
        long long middle = (left + right) / 2;
        if (!worked(middle, grass, N)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    cout << left - 1 << '\n';
    return 0;
}
