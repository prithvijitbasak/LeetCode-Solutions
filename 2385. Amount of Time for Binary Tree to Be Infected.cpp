//Editorial: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/discuss/2456601/BFS-after-Creating-Graph-Full-Explanation
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
    unordered_map<int,vector<int>> graph;
    void createGraph(TreeNode* root)
    {
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it.second!=-1)
            {
                graph[it.second].push_back(it.first->val);
                graph[it.first->val].push_back(it.second);
            }
            if(it.first->left)
                q.push({it.first->left,it.first->val});
            if(it.first->right)
                q.push({it.first->right,it.first->val});
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);
        queue<int> q;
        int ans=0;
        unordered_map<int,int> vis;
        vis[start]=1;
        q.push(start);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int curr=q.front();
                q.pop();
                for(auto it:graph[curr])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            ans+=1;
        }
        return ans-1;
    }
};
