//Editorial: https://leetcode.com/problems/sum-of-left-leaves/discuss/88951/3-line-recursive-c++-solution-no-need-to-explain/1053896
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left and !root->left->left and !root->left->right)
            ans+=root->left->val;
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return ans;
    }
};
