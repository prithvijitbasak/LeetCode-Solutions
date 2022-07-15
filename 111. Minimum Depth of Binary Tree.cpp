//Editorial: https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36071/BFS-C++-8ms-Beats-99.94-submissions
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return 0;
        q.push(root);
        int h=0;
        while(!q.empty())
        {
            h+=1;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(!curr->left and !curr->right)
                    return h;
            }
        }
        return -1;
    }
};
