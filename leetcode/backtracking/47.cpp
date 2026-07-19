class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> curr;
    void add_permutations(vector<int>& nums, unordered_set<int>& visited) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(i) != visited.end()) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] &&
                (visited.find(i - 1) == visited.end())) {
                continue;
            }
            curr.push_back(nums[i]);
            visited.insert(i);
            add_permutations(nums, visited);
            curr.pop_back();
            visited.erase(i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> visited;
        add_permutations(nums, visited);
        return ans;
    }
};