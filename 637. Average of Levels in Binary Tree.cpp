//Editorial: Just apply normal BFS to find the average of all the levels of tree.
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
    typedef long long ll;
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            ll sum=0;
            int temp=sz;
            while(sz--)
            {
                auto curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back((double)sum/temp);
        }
        return ans;
    }
};
