#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    vector<int> min_tree(2 * pN, INT_MAX);
    vector<int> max_tree(2 * pN, 0);
    for (int i = pN; i < pN + N; i++) {
        min_tree[i] = H[i - pN];
        max_tree[i] = H[i - pN];
    }
    for (int i = pN - 1; i >= 1; i--) {
        min_tree[i] = min(min_tree[2 * i], min_tree[2 * i + 1]);
        max_tree[i] = max(max_tree[2 * i], max_tree[2 * i + 1]);
    }
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        swap(H[a], H[b]);
        min_tree[a + pN] = H[a];
        max_tree[a + pN] = H[a];
        min_tree[b + pN] = H[b];
        max_tree[b + pN] = H[b];
        int new_a = a + pN;
        int new_b = b + pN;
        while (new_a >= 2) {
            new_a /= 2;
            min_tree[new_a] = min(min_tree[new_a * 2], min_tree[new_a * 2 + 1]);
            max_tree[new_a] = max(max_tree[2 * new_a], max_tree[2 * new_a + 1]);
            new_b /= 2;
            min_tree[new_b] = min(min_tree[new_b * 2], min_tree[new_b * 2 + 1]);
            max_tree[new_b] = max(max_tree[2 * new_b], max_tree[2 * new_b + 1]);
        }
        new_a = a + pN;
        new_b = b + pN;
        int ans_min = INT_MAX;
        int ans_max = 0;
        while (new_b >= new_a) {
            if (new_a % 2 == 1) {
                ans_min = min(ans_min, min_tree[new_a]);
                ans_max = max(ans_max, max_tree[new_a]);
                new_a++;
            }
            if (new_b % 2 == 0) {
                ans_min = min(ans_min, min_tree[new_b]);
                ans_max = max(ans_max, max_tree[new_b]);
                new_b--;
            }
            new_a /= 2;
            new_b /= 2;
        }
        cout << ans_max - ans_min << '\n';
    }
    return 0;
}