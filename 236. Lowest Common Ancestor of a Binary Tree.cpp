//Editorial: https://youtu.be/_-QHfMDde90
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or p==root or root==q)
            return root;
        TreeNode* lt=lowestCommonAncestor(root->left,p,q);
        TreeNode* rt=lowestCommonAncestor(root->right,p,q);
        if(lt==NULL)
            return rt;
        else if(rt==NULL)
            return lt;
        else
            return root;
    }
};
