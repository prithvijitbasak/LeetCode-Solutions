//Editorial: https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/635419/C++-or-Preorder-traversal-or-simple-logic-or-Detail-explanation
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
    void dfs(TreeNode* root,int maxi)
    {
        if(!root)
            return;
        if(root->val>=maxi)
        {
            ans+=1;
            maxi=max(maxi,root->val);
        }
        if(root->left)
            dfs(root->left,maxi);
        if(root->right)
            dfs(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return ans;
    }
};
