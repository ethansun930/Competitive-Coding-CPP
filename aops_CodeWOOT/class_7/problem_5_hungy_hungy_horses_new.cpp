#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct SegTree {
    vector<int> tree;
    vector<int> notes;
    int size;
    SegTree(int N) {
        size = N;
        while ((size & (size - 1)) != 0) {
            size += size & -size;
        }
        for (int i = 0; i < 2 * size; i++) {
            tree.push_back(0);
            notes.push_back(0);
        }
    }
    void push(int node) {
        tree[2 * node] += notes[node];
        notes[2 * node] += notes[node];
        tree[2 * node + 1] += notes[node];
        notes[2 * node + 1] += notes[node];
        notes[node] = 0;
    }
    void range_add(int val, int l, int r, int tl, int tr, int node) {
        if (tl > tr || tl > r || tr < l) {
            return;
        }
        if (tl >= l && tr <= r) {
            tree[node] += val;
            notes[node] += val;
            return;
        }
        push(node);
        range_add(val, l, r, tl, (tl + tr)/2, 2 * node);
        range_add(val, l, r, (tl + tr)/2 + 1, tr, 2 * node + 1);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]) + notes[node];
    }
    void add(int val, int l, int r) {
        range_add(val, l, r, 1, size, 1);
    }
    int range_max(int l, int r, int tl, int tr, int node, int ans) {
        if (tl > tr || tl > r || tr < l) {
            return ans;
        }
        if (tl >= l && tr <= r) {
            ans = max(ans, tree[node]);
            return ans;
        }
        push(node);
        ans = max(ans, range_max(l, r, tl, (tl + tr)/2, 2 * node, ans));
        ans = max(ans, range_max(l, r, (tl + tr)/2 + 1, tr, 2 * node + 1, ans));
        return ans;
    }
    int maximum(int l, int r) {
        return range_max(l, r, 1, size, 1, INT_MIN);
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    vector<int> rev_S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        rev_S[S[i] - 1] = i + 1;
    }
    int ans = N;
    SegTree tree = SegTree(N);
    tree.add(1, 1, rev_S[N - 1]);
    for (int i = 0; i < N - 1; i++) {
        int h;
        cin >> h;
        tree.add(-1, 1, h);
        while (tree.maximum(1, N) <= 0) {
            ans--;
            tree.add(1, 1, rev_S[ans - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}