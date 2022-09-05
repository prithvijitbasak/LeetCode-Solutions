//Editorial: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C++-BFSDFS
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }
        for(auto it:nodes)
        {
            vector<int> temp;
            for(auto itr:it.second)
                temp.insert(temp.end(),itr.second.begin(),itr.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
