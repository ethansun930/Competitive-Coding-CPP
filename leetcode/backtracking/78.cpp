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
        add_subsets(nums, index + 1);
        curr.push_back(nums[index]);
        add_subsets(nums, index + 1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        add_subsets(nums, 0);
        return ans;
    }
};