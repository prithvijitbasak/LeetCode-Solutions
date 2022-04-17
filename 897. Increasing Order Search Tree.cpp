//Approach 1: Inorder traversal. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/increasing-order-search-tree/solution/
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
    void inorder(TreeNode* root,vector<int> &nums)
    {
        if(!root)
            return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        TreeNode* ans=new TreeNode(0), *curr=ans;
        for(auto it:nums)
        {
            curr->right=new TreeNode(it);
            curr=curr->right;
        }
        return ans->right;
    }
};
//Approach 2: Linking with inorder traversal. TC: O(n) SC: O(h)
//Editorial: https://leetcode.com/problems/increasing-order-search-tree/solution/
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
    TreeNode* curr;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        root->left=nullptr;
        curr->right=new TreeNode(root->val);
        curr=curr->right;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans=new TreeNode(0);
        curr=ans;
        inorder(root);
        return ans->right;
    }
};
