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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        deque<TreeNode*> dq = {root};
        while (dq.size() > 0)
        {
           for (int i = 0; i < dq.size(); i++) {
                TreeNode* node = dq.back();
                dq.pop_back();
                if (node == nullptr)
                    continue;
                if (node->val == subRoot->val && isSameTree(node, subRoot))
                    return true;
                dq.push_back(node->left);
                dq.push_back(node->right);
           }
        }
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p != nullptr && q != nullptr && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
        } else {
            return false;
        }
    }
};
