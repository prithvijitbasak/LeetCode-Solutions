//Editorial: https://youtu.be/ZWGW7FminDM
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
    TreeNode* first=nullptr,*last=nullptr,*middle=nullptr,*prev=nullptr;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        if(prev and (root->val<prev->val))
        {
            if(first==nullptr)
            {
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        // cout<<first->val<<" "<<middle->val<<"\n";
        if(first and last)
            swap(first->val,last->val);
        else if(first and middle)
            swap(first->val,middle->val);
    }
};
