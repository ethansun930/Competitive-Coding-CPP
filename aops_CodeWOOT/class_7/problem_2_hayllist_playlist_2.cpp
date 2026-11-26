#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        S[i]--;
    }
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    vector<bitset<2000>> tree(2 * pN, 0);
    for (int i = 0; i < N; i++) {
       tree[i + pN].set(S[i]);
    }
    for (int i = pN - 1; i >= 0; i--) {
        tree[i] = tree[2 * i] | tree[2 * i + 1];
    }
    for (int q = 0; q < Q; q++) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 'C') {
            tree[x + pN].set(S[x], false);
            tree[x + pN].set(y);
            S[x] = y;
            x += pN;
            x /= 2;
            while (x > 0) {
                tree[x] = tree[2 * x] | tree[2 * x + 1];
                x /= 2;
            }
        }
        else {
            bitset<2000> ans = 0;
            x += pN;
            y += pN;
            while (y >= x && x >= 2) {
                if (x % 2 == 1) {
                    ans |= tree[x];
                    x++;
                }
                if (y % 2 == 0) {
                    ans |= tree[y];
                    y--;
                }
                x /= 2;
                y /= 2;
            }
            if (x == y && y == 1) {
                ans |= tree[1];
            }
            cout << ans.count() << '\n';
        }
    }
    return 0;
}