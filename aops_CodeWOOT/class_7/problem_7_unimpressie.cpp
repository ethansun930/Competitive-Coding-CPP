#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct SegTree {
    vector<int> tree;
    int size;
    SegTree(int N) {
        size = N;
        while ((size & (size - 1)) != 0) {
            size += size & -size;
        }
        for (int i = 0; i < 2 * size; i++) {
            tree.push_back(-1);
        }
    }
    void update_int(int index, int val, int start, int end, int node) {
        if (start > index || end < index) {
            return;
        }
        if (start == end) {
            tree[node] = val;
            return;
        }
        update_int(index, val, start, (start + end)/2, 2 * node);
        update_int(index, val, (start + end)/2 + 1, end, 2 * node + 1);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int index, int val) {
        update_int(index, val, 1, size, 1);
    }
    int find_min(int l, int r, int start, int end, int node) {
        if (start > end || start > r || end < l) {
            return INT_MAX;
        }
        if (start >= l && end <= r) {
            return tree[node];
        }
        int left = find_min(l, r, start, (start + end)/2, 2 * node);
        int right = find_min(l, r, (start + end)/2 + 1, end, 2 * node + 1);
        return min(left, right);
    }
    int minimum(int l, int r) {
        return find_min(l, r, 1, size, 1);
    }
};
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    bool non_zero = false;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        if (A[i] != 0) {
            non_zero = true;
        }
    }
    if (!non_zero) {
        cout << 1 << '\n';
        return;
    }
    SegTree tree = SegTree(N);
    vector<int> last_seen(N, -1);
    vector<bool> mex(N, false);
    for (int i = 0; i < N; i++) {
        if (tree.minimum(1, A[i]) > last_seen[A[i]]) {
            mex[A[i]] = true;
        }
        last_seen[A[i]] = i;
        tree.update(A[i] + 1, i);
    }
    for (int x = 1; x < N; x++) {
        if (tree.minimum(1, x) > last_seen[x]) {
            mex[x] = true;
        }
    }
    for (int i = 1; i < N; i++) {
        if (!mex[i]) {
            cout << i + 1 << '\n';
            return;
        }
    }
    bool everything = true;
    for (int i = 0; i < N; i++) {
        if (last_seen[i] == -1) {
            everything = false;
        }
    }
    if (everything) {
        cout << N + 2 << '\n';
    }
    else {
        cout << N + 1 << '\n';
    }
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
/*
-1 -1 -1
f f t
*/