//Approach 1:Recursive
//Editorial: https://leetcode.com/problems/trim-a-binary-search-tree/discuss/1947897/Easy-To-Understand-with-Explanation-oror-0ms-oror-100-faster-(*)o
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        if(root->val>=low and root->val<=high)
        {
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
        }
        else if(root->val<low)
            root=trimBST(root->right,low,high);
        else
            root=trimBST(root->left,low,high);
        return root;
    }
};
//Approach 2: Iterative
//Editorial: https://leetcode.com/problems/trim-a-binary-search-tree/solution/838496
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root)
        {
            if(root->val<low)
                root=root->right;
            else if(root->val>high)
                root=root->left;
            else
                break;
        }
        if(root==nullptr)
            return root;
        TreeNode* leftsub=root;
        while(leftsub->left)
        {
            if(leftsub->left->val<low)
                leftsub->left=leftsub->left->right;
            else
                leftsub=leftsub->left;
        }
        TreeNode* rightsub=root;
        while(rightsub->right)
        {
            if(rightsub->right->val>high)
                rightsub->right=rightsub->right->left;
            else
                rightsub=rightsub->right;
        }
        return root;
    }
};
