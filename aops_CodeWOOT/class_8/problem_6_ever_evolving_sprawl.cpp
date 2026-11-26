#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<vector<int>>& children, vector<int>& enter, vector<int>& exit, vector<int>& depth, int& time, vector<vector<int>>& jump) {
    enter[node] = time;
    time++;
    for (int child : children[node]) {
        depth[child] = depth[node] + 1;
        jump[child][0] = node;
        DFS(child, children, enter, exit, depth, time, jump);
    }
    exit[node] = time;
    time++;
}
struct Fenwick_Tree {
    vector<int> tree;
    int size;
    Fenwick_Tree(int N) {
        size = N + 1;
        while ((size & (size - 1)) != 0) {
            size += size & -size;
        }
        for (int i = 0; i < size; i++) {
            tree.push_back(0);
        }
    }
    void increment(int index) {
        int new_idx = index;
        while (new_idx < size) {
            tree[new_idx]++;
            new_idx += new_idx & -new_idx;
        }
    }
    int prefix_sum(int index) {
        int new_idx = index;
        int ans = 0;
        while (new_idx >= 1) {
            ans += tree[new_idx];
            new_idx -= new_idx & -new_idx;
        }
        return ans;
    }
    int sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> parent(N + Q, 0);
    vector<vector<int>> children(N + Q);
    for (int i = 1; i < N + Q; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }
    vector<int> enter(N + Q);
    vector<int> exit(N + Q);
    vector<int> depth(N + Q, 0);
    vector<vector<int>> jump(N + Q, vector<int>(20, 0));
    int time = 1;
    DFS(0, children, enter, exit, depth, time, jump);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < N + Q; j++) {
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }
    Fenwick_Tree tree = Fenwick_Tree(2 * (N + Q));
    tree.increment(enter[0]);
    int c = 0;
    for (int i = 1; i < N + Q; i++) {
        tree.increment(enter[i]);
        int v;
        int s;
        if (enter[c] <= enter[i] && exit[i] <= exit[c]) {
            int new_i = i;
            for (int j = 19; j >= 0; j--) {
                if (depth[jump[new_i][j]] > depth[c]) {
                    new_i = jump[new_i][j];
                }
            }
            v = new_i;
            s = tree.sum(enter[v], exit[v]);
        }
        else {
            v = parent[c];
            s = i + 1 - tree.sum(enter[c], exit[c]);
        }
        if (s > (i + 1)/2) {
            c = v;
        }
        else if (i % 2 == 1 && s == (i + 1)/2 && v < c) {
            c = v;
        }
        if (i >= N) {
            cout << c + 1 << '\n';
        }
    }
    return 0;
}