//Editorial: https://youtu.be/nKggNAiEpBE
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
    bool isSymmetric(TreeNode* root) {
        return root==NULL or isval(root->left,root->right);
    }
    bool isval(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL or t2==NULL)
            return t1==t2;
        if(t1->val!=t2->val)
            return false;
        return isval(t1->left,t2->right) and isval(t1->right,t2->left);
    }
};
