//Editorial: https://leetcode.com/problems/n-ary-tree-preorder-traversal/discuss/149093/C%2B%2B-44ms-beats-100-both-iterative-and-recursive
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
        ans.push_back(root->val);
        for(Node* child:root->children)
            travel(child,ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        travel(root,ans);
        return ans;
    }
};
