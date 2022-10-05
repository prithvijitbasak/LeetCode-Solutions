//Editorial: https://leetcode.com/problems/add-one-row-to-tree/solution/
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
    void insert(TreeNode* root, int val, int currd, int d)
    {
        if(!root)
            return;
        if(currd==d-1)
        {
            TreeNode* temp=root->left;
            root->left=new TreeNode(val);
            root->left->left=temp;
            temp=root->right;
            root->right=new TreeNode(val);
            root->right->right=temp;
        }
        insert(root->left,val,currd+1,d);
        insert(root->right,val,currd+1,d);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1)
        {
            TreeNode* curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }
        insert(root, val, 1, d);
        return root;
    }
};
