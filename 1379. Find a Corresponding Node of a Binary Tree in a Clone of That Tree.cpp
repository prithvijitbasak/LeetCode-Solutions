//Editorial: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/2046226/C++-dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void dfs(TreeNode* ori,TreeNode* clone,TreeNode* target)
    {
        if(!ori)
            return;
        if(ori==target)
            ans=clone;
        dfs(ori->left,clone->left,target);
        dfs(ori->right,clone->right,target);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned,target);
        return ans;
    }
};
