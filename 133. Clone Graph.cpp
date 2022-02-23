//Editorial: https://youtu.be/f2EfGComRKM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr,Node* node,vector<Node*> &vis)
    {
        vis[node->val]=node;
        for(auto it:curr->neighbors)
        {
            if(!vis[it->val])
            {
                Node* newnode=new Node(it->val);
                (node->neighbors).push_back(newnode);
                dfs(it,newnode,vis);
            }
            else
                (node->neighbors).push_back(vis[it->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        vector<Node*> vis(1000,NULL);
        Node* copy=new Node(node->val);
        vis[node->val]=copy;
        for(auto curr:node->neighbors)
        {
            if(!vis[curr->val])
            {
                Node* newnode=new Node(curr->val);
                (copy->neighbors).push_back(newnode);
                dfs(curr,newnode,vis);
            }
            else
                (copy->neighbors).push_back(vis[curr->val]);
        }
        return copy;
    }
};
