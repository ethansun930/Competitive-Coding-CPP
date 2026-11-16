#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct SegTree {
    vector<long long> tree;
    long long size;
    SegTree(long long N) {
        size = N;
        while ((size & (size - 1)) != 0) {
            size += size & -size;
        }
        for (long long i = 0; i < 2 * size; i++) {
            tree.push_back(LLONG_MIN);
        }
    }
    void update_int(long long index, long long val, long long start, long long end, long long node) {
        if (start > index || end < index) {
            return;
        }
        if (start == end) {
            tree[node] = val;
            return;
        }
        update_int(index, val, start, (start + end)/2, 2 * node);
        update_int(index, val, (start + end)/2 + 1, end, 2 * node + 1);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    void update(long long index, long long val) {
        if (val > tree[index + size - 1]) {
            update_int(index, val, 1, size, 1);
        }
    }
    long long find_max(long long l, long long r, long long start, long long end, long long node) {
        if (start > end || start > r || end < l) {
            return LLONG_MIN;
        }
        if (start >= l && end <= r) {
            return tree[node];
        }
        long long left = find_max(l, r, start, (start + end)/2, 2 * node);
        long long right = find_max(l, r, (start + end)/2 + 1, end, 2 * node + 1);
        return max(left, right);
    }
    long long maximum(long long l, long long r) {
        return find_max(l, r, 1, size, 1);
    }
};
void solve() {
    long long N, C, M;
    cin >> N >> C >> M;
    vector<long long> T(M + 1);
    vector<long long> F(M + 1);
    T[0] = 1;
    F[0] = 0;
    for (long long i = 1; i <= M; i++) {
        cin >> T[i] >> F[i];
    }
    SegTree seg_right = SegTree(N);
    seg_right.update(1, -C);
    SegTree seg_left = SegTree(N);
    seg_left.update(1, C);
    long long ans = 0;
    for (long long i = 1; i <= M; i++) {
        long long dp = seg_left.maximum(1, T[i]) - C * T[i] + F[i];
        long long right = seg_right.maximum(T[i], N);
        if (right != LLONG_MIN) {
            dp = max(dp, right + C * T[i] + F[i]);
        }
        seg_left.update(T[i], dp + C * T[i]);
        seg_right.update(T[i], dp - C * T[i]);
        ans = max(ans, dp);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}