//Editorial: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/discuss/2590049/C++-or-Use-BFS-or-Simple-and-Efficient-approach
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> values;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(level&1)
                    curr->val=values[sz-i-1];
                if(curr->left)
                {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            values=temp;
            level+=1;
        }
        return root;
    }
};
