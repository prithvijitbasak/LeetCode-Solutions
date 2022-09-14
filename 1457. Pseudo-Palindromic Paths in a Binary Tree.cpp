//Editorial: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/648304/C++-DFS-+-Bitvector
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
    void dfs(TreeNode* root,int bits)
    {
        if(!root)
            return;
        if(!root->left and !root->right)
        {
            ans+=(__builtin_popcount(bits^(1<<root->val))<=1);
            return;
        }
        dfs(root->left,bits^(1<<root->val));
        dfs(root->right,bits^(1<<root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
