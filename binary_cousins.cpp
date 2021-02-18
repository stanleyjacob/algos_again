/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* node, const int& value, int& level) {
        if (node->val == value) {
            return;
        }
        level += 1;
        if (value < node->val) {
            helper(node->left, value, level);
        }
        else {
            helper(node->right, value, level);
        }
    }
    
    int findNode(TreeNode* node, const int& value) {
        int curr_level = 0;
        helper(node, value, curr_level);
        return curr_level;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        // search for x, find level
        // search for y, find level
        // check if levels match
        int x_level = findNode(root, x);
        int y_level = findNode(root, y);
        if (x_level == y_level) {
            return true;
        }
        return false;
    }
};
