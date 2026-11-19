#include<iostream>
#include<vector>
using namespace std;

struct Fenwick_tree {
    vector<vector<int>> tree;
    int size = 0;
    Fenwick_tree(int N) {
        size = N + 1;
        while ((size & (size - 1)) != 0) {
            size += size & -size;
        }
        for (int i = 0; i < size; i++) {
            tree.push_back({});
            for (int j = 0; j < size; j++) {
                tree[i].push_back(0);
            }
        }
    }
    void increase(int r, int c) {
        int i = r;
        while (i < size) {
            int j = c;
            while (j < size) {
                tree[i][j]++;
                j += j & -j;
            }
            i += i & -i;
        }
    }
    int prefix_sum(int r, int c) {
        int ans = 0;
        int i = r;
        while (i >= 1) {
            int j = c;
            while (j >= 1) {
                ans += tree[i][j];
                j -= j & -j;
            }
            i -= i & -i;
        }
        return ans;
    }
    int sum(int r1, int r2, int c1, int c2) {
        return prefix_sum(r2, c2) - prefix_sum(r2, c1 - 1) - prefix_sum(r1 - 1, c2) + prefix_sum(r1 - 1, c1 - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    Fenwick_tree tree = Fenwick_tree(2001);
    for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;
        if (type == 'F') {
            int x, y;
            cin >> x >> y;
            tree.increase(x + 1, y + 1);
        }
        else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << tree.sum(a + 1, c + 1, b + 1, d + 1) << '\n';
        }
    }
    return 0;
}