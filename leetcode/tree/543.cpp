/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int ans = 0;
    pair<int, int> findLongestPaths(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return make_pair(0, 0);
        }
        if (root->left == nullptr) {
            int leftlength = 0;
            pair<int, int> right = findLongestPaths(root->right);
            int rightlength = max(right.first, right.second);
            ans = max(ans, leftlength + rightlength + 1);
            return make_pair(leftlength, rightlength + 1);
        }
        if (root->right == nullptr) {
            int rightlength = 0;
            pair<int, int> left = findLongestPaths(root->left);
            int leftlength = max(left.first, left.second);
            ans = max(ans, leftlength + rightlength + 1);
            return make_pair(leftlength + 1, rightlength);
        }
        pair<int, int> left = findLongestPaths(root->left);
        int leftlength = max(left.first, left.second);
        pair<int, int> right = findLongestPaths(root->right);
        int rightlength = max(right.first, right.second);
        ans = max(ans, leftlength + rightlength + 2);
        return make_pair(leftlength + 1, rightlength + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findLongestPaths(root);
        return ans;
    }
};