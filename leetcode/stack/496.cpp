class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums;
        for (int i = 0; i < nums2.size(); i++) {
            nums[nums2[i]] = i;
        }
        vector<int> greater_elements(nums2.size(), -1);
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[s.top()] < nums2[i]) {
                greater_elements[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(greater_elements[nums[nums1[i]]]);
        }
        return ans;
    }
};