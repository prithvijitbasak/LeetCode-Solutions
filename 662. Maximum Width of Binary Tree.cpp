//Editorial: https://youtu.be/ZbybYvcVLks
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=INT_MIN;
        while(!q.empty())
        {
            int val=q.front().second;
            int sz=q.size();
            int l,r;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front().first;
                long long int idx=q.front().second-val;
                q.pop();
                if(i==0)
                    l=idx;
                if(i==sz-1)
                    r=idx;
                if(node->left)
                    q.push({node->left,(idx*2)+1});
                if(node->right)
                    q.push({node->right,(idx*2)+2});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
