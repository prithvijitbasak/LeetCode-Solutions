//Editorial: https://leetcode.com/problems/path-sum/discuss/670515/C%2B%2B-Recursive-solution-4-lines-code
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        int sum=targetSum;
        sum-=root->val;
        if(!root->right and !root->left and sum==0)
            return true;
        return (hasPathSum(root->left,sum) or hasPathSum(root->right,sum));
    }
};
