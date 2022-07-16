//Editorial: https://leetcode.com/problems/path-sum-iii/discuss/683906/C++-DFS-clean-solution-T-:-89-M-:-80
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
    typedef long long ll;
    ll ans=0;
    void dfs(TreeNode* root,ll sum)
    {
        if(!root)
            return;
        sum-=root->val;
        if(sum==0)
            ans+=1;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        dfs(root,sum);
        if(root->left)
            pathSum(root->left,sum);
        if(root->right)
            pathSum(root->right,sum);
        return ans;
    }
};
