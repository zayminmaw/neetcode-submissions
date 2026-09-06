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
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }

    bool validate(TreeNode* node, int left, int right) {
        if (node == nullptr)
            return true;
        if (!(node->val < right && node->val > left)) 
            return false;
        return validate(node->left, left, node->val) && validate(node->right, node->val, right);
    }
};
