//Editorial: https://leetcode.com/problems/binary-tree-tilt/discuss/102334/Java-Solution-post-order-traversal
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
    int ans=0;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        ans+=abs(l-r);
        return l+r+(root->val);
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return ans;
    }
};
