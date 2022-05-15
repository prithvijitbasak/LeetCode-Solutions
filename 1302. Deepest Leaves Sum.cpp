//Editorial: https://leetcode.com/problems/deepest-leaves-sum/discuss/1152947/Deepest-Leaves-Sum-or-Short-and-Easy-Solutions-w-Explanation-or-BFS-and-DFS-Approach
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0,n;
        while(!q.empty())
        {
            ans=0,n=q.size();
            for(int i=1;i<=n;i++)
            {
                auto node=q.front();
                q.pop();
                ans+=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
