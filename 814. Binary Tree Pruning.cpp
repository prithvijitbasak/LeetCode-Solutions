//Editorial: https://leetcode.com/problems/binary-tree-pruning/solution/
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
    bool containsOne(TreeNode* root)
    {
        if(!root)
            return false;
        bool leftContainsOne=containsOne(root->left);
        bool rightContainsOne=containsOne(root->right);
        if(!leftContainsOne)
            root->left=nullptr;
        if(!rightContainsOne)
            root->right=nullptr;
        return root->val==1 or leftContainsOne or rightContainsOne;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : nullptr;
    }
};
