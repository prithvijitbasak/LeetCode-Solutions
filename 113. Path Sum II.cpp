//Editorial: https://leetcode.com/problems/path-sum-ii/discuss/36685/12ms-11-lines-C++-Solution
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
    void solve(TreeNode* root,vector<vector<int>> &ans,vector<int> &path,int sum)
    {
        if(!root)
            return;
        path.push_back(root->val);
        sum-=root->val;
        if(!root->left and !root->right and sum==0)
            ans.push_back(path);
        solve(root->left,ans,path,sum);
        solve(root->right,ans,path,sum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root,ans,path,targetSum);
        return ans;
    }
};
