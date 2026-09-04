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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        deque<TreeNode*> dq = {root};
        while (dq.size() > 0) {
            int level = dq.size();
            int val;
            bool found = false;
            for (int i = 0; i < level; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (node == nullptr)
                    continue;
                found = true;
                val = node->val;
                dq.push_back(node->left);
                dq.push_back(node->right);
            }
            if (found)
                res.push_back(val);
        }
        return res;
    }
};
