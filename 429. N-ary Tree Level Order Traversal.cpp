//Editorial: https://leetcode.com/problems/n-ary-tree-level-order-traversal/discuss/1386593/C++Python-BFS-and-DFS-Solutions-Clean-and-Concise
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                Node* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                for(auto it:curr->children)
                    q.push(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
