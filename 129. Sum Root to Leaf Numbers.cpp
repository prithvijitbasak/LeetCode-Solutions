//Editorial: https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1556417/C++Python-Recursive-and-Iterative-DFS-+-BFS-+-Morris-Traversal-O(1)-or-Beats-100
//Approach 1: Iterative using stack. TC: O(n) SC; O(n)
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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,0});
        while(!stk.empty())
        {
            TreeNode* curr=stk.top().first;
            int sum=stk.top().second;
            stk.pop();
            sum=sum*10+curr->val;
            if(!curr->left and !curr->right)
                ans+=sum;
            if(curr->left)
                stk.push({curr->left,sum});
            if(curr->right)
                stk.push({curr->right,sum});
        }
        return ans;
    }
};
//Approach 2: Using morris traversal. TC: O(n) SC: O(1)
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
    int sumNumbers(TreeNode* root) {
        int ans=0,sum=0,depth=0;
        while(root)
        {
            if(!root->left)
            {
                sum=sum*10+root->val;
                if(!root->right)
                    ans+=sum;
                root=root->right;
            }
            else
            {
                depth=1;
                TreeNode* prev=root->left;
                while(prev->right and prev->right!=root)
                    prev=prev->right,depth+=1;
                if(!prev->right)
                {
                    prev->right=root;
                    sum=sum*10+root->val;
                    root=root->left;
                }
                else
                {
                    prev->right=nullptr;
                    if(!prev->left)
                        ans+=sum;
                    sum/=pow(10,depth);
                    root=root->right;
                }
            }
        }
        return ans;
    }
};
