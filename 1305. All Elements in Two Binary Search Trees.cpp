//Editorial: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/1719941/C%2B%2B-oror-Best-Explanation-oror-Naive-and-Optimal
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> stk1,stk2;
        while(root1 or root2 or !stk1.empty() or !stk2.empty())
        {
            while(root1)
            {
                stk1.push(root1);
                root1=root1->left;
            }
            while(root2)
            {
                stk2.push(root2);
                root2=root2->left;
            }
            if(stk2.empty() or (!stk1.empty() and stk1.top()->val<=stk2.top()->val))
            {
                root1=stk1.top();
                stk1.pop();
                ans.push_back(root1->val);
                root1=root1->right;
            }
            else
            {
                root2=stk2.top();
                stk2.pop();
                ans.push_back(root2->val);
                root2=root2->right;
            }
        }
        return ans;
    }
};
