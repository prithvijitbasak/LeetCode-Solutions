//Editorial: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/929000/Recursive-solution-long-explanation
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
    // vector<TreeNode*> ans;
    vector<TreeNode*> solve(int start,int end)
    {
        if(start>end)
            return {nullptr};
        vector<TreeNode*> lefttree,righttree,ans;
        for(int i=start;i<=end;i++)
        {
            lefttree=solve(start,i-1);
            righttree=solve(i+1,end);
            TreeNode* node=new TreeNode(i);
            for(auto l:lefttree)
            {
                for(auto r:righttree)
                {
                    TreeNode* node=new TreeNode(i);
                    node->left=l;
                    node->right=r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        // return ans;
    }
};
