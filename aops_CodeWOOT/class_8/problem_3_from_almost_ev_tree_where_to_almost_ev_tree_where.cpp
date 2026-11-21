#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    vector<int> parent(N, 0);
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
    }
    vector<long long> depth(N, 0);
    vector<vector<int>> jump(N, vector<int>(20, 0));
    for (int i = 1; i < N; i++) {
        depth[i] = depth[parent[i]] + 1;
        jump[i][0] = parent[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < N; j++) {
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int new_a = a;
        int new_b = b;
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        for (int i = 19; i >= 0; i--) {
            if (depth[jump[a][i]] >= depth[b]) {
                a = jump[a][i];
            }
        }
        int lca = a;
        if (a != b) {
            for (int i = 19; i >= 0; i--) {
                if (jump[a][i] == jump[b][i]) {
                    lca = jump[a][i];
                }
                else {
                    a = jump[a][i];
                    b = jump[b][i];
                }
            }
        }
        cout << depth[new_a] + depth[new_b] - 2 * depth[lca] << '\n';
    }
    return 0;
}