#include <vector>
using namespace std;

class DSU {
   public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }
    bool unify(int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if (rooti == rootj) {
            return true;
        }
        parent[rooti] = rootj;
        return false;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu = DSU(edges.size());

        for (const vector<int>& edge : edges) {
            if (dsu.unify(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }
        return {0, 0};
    }
};