//Editorial: https://leetcode.com/problems/kth-smallest-element-in-a-bst/solution/
//Approach 1: Recursive inorder. TC: O(n) SC: O(n)
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
    vector<int> nums;
    void inorder(TreeNode* root,int k)
    {
        if(root==nullptr)
            return;
        inorder(root->left,k);
        nums.push_back(root->val);
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return nums[k-1];
    }
};
//Approach 2: Iterative inorder using stack. TC: O(n) SC: O(h) //average case in worst case it is O(n)
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true)
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(--k==0)
                return root->val;
            root=root->right;
        }
    }
};
