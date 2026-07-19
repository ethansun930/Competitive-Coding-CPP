class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> greater_elements(nums.size(), -1);
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                greater_elements[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = nums.size(); i < 2 * nums.size(); i++) {
            while (!s.empty() &&
                   nums[s.top() % nums.size()] < nums[i - nums.size()]) {
                greater_elements[s.top() % nums.size()] = nums[i - nums.size()];
                s.pop();
            }
            s.push(i);
        }
        return greater_elements;
    }
};