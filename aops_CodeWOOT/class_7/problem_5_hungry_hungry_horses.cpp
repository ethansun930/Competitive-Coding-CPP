#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int pN = N;
    while ((pN & (pN - 1)) != 0) {
        pN += pN & -pN;
    }
    vector<int> tree(2 * pN, 0);
    for (int i = 0; i < N; i++) {
        cin >> tree[i + pN];
    }
    for (int i = pN - 1; i >= 0; i--) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    for (int i = 0; i < N - 1; i++) {
        int h;
        cin >> h;
        int maximum = 0;
        int node = 0;
        int curr = 1;
        int comp = pN/2;
        while (curr < pN) {
            if (h > comp) {
                if (tree[2 * curr] > maximum) {
                    maximum = tree[2 * curr];
                    node = 2 * curr;
                }
                curr = 2 * curr + 1;
                h -= comp;
            }
            else {
                curr *= 2;
            }
            comp /= 2;
        }
        if (tree[curr] > maximum) {
            maximum = tree[curr];
            node = curr;
        }
        while (node < pN) {
            if (tree[2 * node] == maximum) {
                node *= 2;
            }
            else {
                node = 2 * node + 1;
            }
        }
        tree[node] = 0;
        node /= 2;
        while (node >= 1) {
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            node /= 2;
        }
        for (int i = 1; i < 2 * pN; i++) {
            cout << tree[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
h = 4
maximum = 0
node = 0
curr = 1
comp = 4
       5
   5       4
 5   3   4   0
0 5 3 1 4 0 0 0
*/