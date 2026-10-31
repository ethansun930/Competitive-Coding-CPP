#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    vector<long long> tree(2 * pN, 0);
    for (int b = 0; b < B; b++) {
        int S, E, C;
        long long G;
        cin >> S >> E >> G >> C;
        S--;
        tree[S + pN] += G;
        if (E != pN) {
            tree[E + pN] -= G;
        }
        S += pN;
        E += pN;
        while (S >= 2) {
            S /= 2;
            tree[S] = tree[2 * S] + tree[2 * S + 1];
        }
        if (E != 2 * pN) {
            while (E >= 2) {
                E /= 2;
                tree[E] = tree[2 * E] + tree[2 * E + 1];
            }
        }
        int pointer = 1;
        int comp = pN/2;
        long long ans = tree[C + pN - 1];
        while (pointer < pN) {
            if (C > comp) {
                ans += tree[2 * pointer];
                C -= comp;
                comp /= 2;
                pointer = 2 * pointer + 1;
            }
            else {
                comp /= 2;
                pointer *= 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
   0
  1 -1
1 -2 0 -1
   -2
  -1 -1
3 -2 0 -1
*/