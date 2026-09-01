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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        deque<TreeNode*> dq = {root};
        while (dq.size() > 0)
        {
            vector<int> inner_res; 
            int level = dq.size();
            for (int i = 0; i < level; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (node == nullptr)
                    continue;
                inner_res.push_back(node->val);
                dq.push_back(node->left);
                dq.push_back(node->right);
            }
            if (inner_res.size() > 0)
                res.push_back(inner_res);
        }
        return res;
    }
};
