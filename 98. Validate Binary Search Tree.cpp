//Editorial: https://youtu.be/f-sj7I5oXEI
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
    bool isvalid(TreeNode* root,long mnval,long mxval)
    {
        if(!root)
            return true;
        if(root->val<=mnval or root->val>=mxval)
            return false;
        return isvalid(root->left,mnval,root->val) and isvalid(root->right,root->val,mxval);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LONG_MIN,LONG_MAX);
    }
};
