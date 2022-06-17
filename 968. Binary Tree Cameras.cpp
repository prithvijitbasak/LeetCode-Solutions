//Editorial: https://leetcode.com/problems/binary-tree-cameras/discuss/211412/C++-DFS-simplest
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
    int noCamera=0,notNeeded=1,hasCamera=2;
    int ans=0;
    int dfs(TreeNode* root)
    {
        if(!root)
            return notNeeded;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==noCamera or right==noCamera)
        {
            ans+=1;
            return hasCamera;
        }
        else if(left==hasCamera or right==hasCamera)
            return notNeeded;
        else
            return noCamera;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==noCamera)
            ans+=1;
        return ans;
    }
};
