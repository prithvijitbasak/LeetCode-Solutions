//Approach 1: Using stack TC: O(n) and SC: O(n)
//Editorial: https://youtu.be/Bfqd8BsPVuw
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root)
            return preorder;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            root=stk.top();
            stk.pop();
            preorder.push_back(root->val);
            if(root->right)
                stk.push(root->right);
            if(root->left)
                stk.push(root->left);
        }
        return preorder;
    }
};
//Approach 2: Efficient solution using morris traversal technique
//Editorial: https://youtu.be/80Zug6D1_r4
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr)
                    prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};
