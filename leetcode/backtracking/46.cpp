#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    void add_permutations(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        add_permutations(nums, index + 1);
        for (int i = index + 1; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            add_permutations(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        add_permutations(nums, 0);
        return ans;
    }
};