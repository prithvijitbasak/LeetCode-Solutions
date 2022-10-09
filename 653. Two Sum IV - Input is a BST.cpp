//Editorial: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106059/JavaC++-Three-simple-methods-choose-one-you-like
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
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,root,k);
    }
    bool dfs(TreeNode* root, TreeNode* curr, int value)
    {
        if(!curr)
            return false;
        return search(root,curr,value-curr->val) or dfs(root,curr->left,value) or dfs(root,curr->right,value);
    }
    bool search(TreeNode* root, TreeNode* curr, int value)
    {
        if(!root)
            return false;
        return ((root->val==value) and (root!=curr)) or ((root->val<value) and search(root->right,curr,value)) or ((root->val>value) and search(root->left,curr,value));
    }
};
