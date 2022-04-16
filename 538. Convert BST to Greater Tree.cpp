//Approach 1: Recursive. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/convert-bst-to-greater-tree/solution/
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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->right==nullptr)
            {
                sum+=curr->val;
                curr->val=sum;
                curr=curr->left;
            }
            else
            {
                TreeNode* prev=curr->right;
                while(prev->left and prev->left!=curr)
                    prev=prev->left;
                if(prev->left==nullptr)
                {
                    prev->left=curr;
                    curr=curr->right;
                }
                else
                {
                    prev->left=nullptr;
                    sum+=curr->val;
                    curr->val=sum;
                    curr=curr->left;
                }
            }
        }
        return root;
    }
};
