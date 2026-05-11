class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> curr;
    void add_combinations(vector<int>& candidates, int target, int index) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        if (target >= candidates[index]) {
            curr.push_back(candidates[index]);
            add_combinations(candidates, target - candidates[index], index);
            curr.pop_back();
        }
        add_combinations(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        add_combinations(candidates, target, 0);
        return ans;
    }
};