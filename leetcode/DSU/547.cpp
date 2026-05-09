#include <vector>
using namespace std;

class Solution {
   public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
    void unify(int i, int j, vector<int>& parent) {
        int rooti = find(i, parent);
        int rootj = find(j, parent);
        if (rooti != rootj) {
            parent[rooti] = rootj;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parent(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            parent[i] = i;
        }
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1) {
                    unify(i, j, parent);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (parent[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};