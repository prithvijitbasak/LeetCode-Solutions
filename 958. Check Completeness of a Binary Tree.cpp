//Editorial: https://leetcode.com/problems/check-completeness-of-a-binary-tree/editorial
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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto curr=q.front();
                q.pop();
                if(curr==nullptr)
                    f=1;
                else
                {
                    if(f)
                        return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};
