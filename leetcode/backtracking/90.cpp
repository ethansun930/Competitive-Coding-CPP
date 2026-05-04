#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> curr;
    void add_subsets(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }
        int dups = 1;
        while (index + dups < nums.size() &&
               nums[index + dups] == nums[index]) {
            dups++;
        }
        add_subsets(nums, index + dups);
        for (int i = 0; i < dups; i++) {
            curr.push_back(nums[index]);
            add_subsets(nums, index + dups);
        }
        for (int i = 0; i < dups; i++) {
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        add_subsets(nums, 0);
        return ans;
    }
};