#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    vector<int> tree(2 * pN, 0);
    vector<int> notes(2 * pN, 0);
    for (int q = 0; q < Q; q++) {
        char t;
        cin >> t;
        if (t == 'F') {
            int l, r, h;
            cin >> l >> r >> h;
            int new_l = l;
            int new_r = r;
            if (l == r) {
                tree[l + pN - 1] += h;
                l += pN - 1;
                l >>= 1;
                while (l >= 1) {
                    tree[l] = max(tree[2 * l], tree[2 * l + 1]) + notes[l];
                    l >>= 1;
                }
                continue;
            }
            int L = 1;
            int R = 1;
            int layer_comp = pN/2;
            while (R - L != 1) {
                if (l > layer_comp) {
                    L <<= 1;
                    L++;
                    l -= layer_comp;
                }
                else {
                    L <<= 1;
                }
                if (r > layer_comp) {
                    R <<= 1;
                    R++;
                    r -= layer_comp;
                }
                else {
                    R <<= 1;
                }
                layer_comp >>= 1;
            }
            while (L < pN) {
                if (l > layer_comp) {
                    L <<= 1;
                    L++;
                    l -= layer_comp;
                }
                else {
                    tree[2 * L + 1] += h;
                    notes[2 * L + 1] += h;
                    L <<= 1;
                }
                if (r > layer_comp) {
                    tree[2 * R] += h;
                    notes[2 * R] += h;
                    R <<= 1;
                    R++;
                    r -= layer_comp;
                }
                else {
                    R <<= 1;
                }
                layer_comp >>= 1;
            }
            tree[L] += h;
            tree[R] += h;
            l = new_l;
            r = new_r;
            l += pN - 1;
            r += pN - 1;
            l >>= 1;
            r >>= 1;
            while (l >= 1) {
                tree[l] = max(tree[2 * l], tree[2 * l + 1]) + notes[l];
                tree[r] = max(tree[2 * r], tree[2 * r + 1]) + notes[r];
                l >>= 1;
                r >>= 1;
            }
            continue;
        }
        int l, r;
        cin >> l >> r;
        if (l == r) {
            int new_l = l;
            int L = 1;
            int comp = pN/2;
            while (L < pN) {
                tree[2 * L] += notes[L];
                notes[2 * L] += notes[L];
                tree[2 * L + 1] += notes[L];
                notes[2 * L + 1] += notes[L];
                notes[L] = 0;
                if (l > comp) {
                    L <<= 1;
                    L++;
                    l -= comp;
                }
                else {
                    L <<= 1;
                }
                comp >>= 1;
            }
            cout << tree[new_l + pN - 1] << '\n';
            continue;
        }
        int new_l = l;
        int new_r = r;
        int ans = 0;
        int L = 1;
        int R = 1;
        int layer_comp = pN/2;
        while (R - L != 1) {
            tree[2 * L] += notes[L];
            notes[2 * L] += notes[L];
            tree[2 * L + 1] += notes[L];
            notes[2 * L + 1] += notes[L];
            notes[L] = 0;
            if (l > layer_comp) {
                L <<= 1;
                L++;
                l -= layer_comp;
            }
            else {
                L <<= 1;
            }
            if (r > layer_comp) {
                R <<= 1;
                R++;
                r -= layer_comp;
            }
            else {
                R <<= 1;
            }
            layer_comp >>= 1;
        }
        while (L < pN) {
            tree[2 * L] += notes[L];
            notes[2 * L] += notes[L];
            tree[2 * L + 1] += notes[L];
            notes[2 * L + 1] += notes[L];
            notes[L] = 0;
            tree[2 * R] += notes[R];
            notes[2 * R] += notes[R];
            tree[2 * R + 1] += notes[R];
            notes[2 * R + 1] += notes[R];
            notes[R] = 0;
            if (l > layer_comp) {
                L <<= 1;
                L++;
                l -= layer_comp;
            }
            else {
                ans = max(ans, tree[2 * L + 1]);
                L <<= 1;
            }
            if (r > layer_comp) {
                ans = max(ans, tree[2 * R]);
                R <<= 1;
                R++;
                r -= layer_comp;
            }
            else {
                R <<= 1;
            }
            layer_comp >>= 1;
        }
        ans = max(ans, tree[new_l + pN - 1]);
        ans = max(ans, tree[new_r + pN - 1]);
        cout << ans << '\n';
    }
    return 0;
}