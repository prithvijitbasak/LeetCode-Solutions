//Editorial: https://leetcode.com/problems/minimum-distance-between-bst-nodes/discuss/114832/C++-Solution-Not-save-element-in-list-then-compare
class Solution {
public:
    void solve(TreeNode* root,int &ans,int &prev)
    {
        if(root)
        {
            solve(root->left,ans,prev);
            if(prev!=-1)
                ans=min(ans,root->val-prev);
        
            prev=root->val;
            solve(root->right,ans,prev);
        }
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int prev=-1;
        solve(root,ans,prev);
        return ans;
    }
};
