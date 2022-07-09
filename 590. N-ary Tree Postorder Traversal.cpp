//Editorial: https://leetcode.com/problems/n-ary-tree-postorder-traversal/discuss/1567050/C++-oror-Easy-to-understand-oror-Recursive-Solution
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
    void travel(Node* root,vector<int> &ans)
    {
        if(!root)
            return;
        for(auto it:root->children)
            travel(it,ans);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        travel(root,ans);
        return ans;
    }
};
