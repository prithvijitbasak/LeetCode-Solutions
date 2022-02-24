//Editorial: https://youtu.be/FiFiNvM29ps
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(!root)
            return node;
        TreeNode* curr=root;
        while(true)
        {
            if(curr->val<val)
            {
                if(curr->right)
                    curr=curr->right;
                else
                {
                    curr->right=node;
                    break;
                }
            }
            else
            {
                if(curr->left)
                    curr=curr->left;
                else
                {
                    curr->left=node;
                    break;
                }
            }
        }
        return root;
    }
};
