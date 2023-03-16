//Editorial: https://youtu.be/aZNaLrVebKQ
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
    map<int,int> mp;
    TreeNode* solve(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend)
    {
        if(prestart>preend or instart>inend)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inrootpos=mp[root->val];
        int numleft=inrootpos-instart;
        root->left=solve(preorder,prestart+1,prestart+numleft,inorder,instart,inrootpos-1);
        root->right=solve(preorder,prestart+numleft+1,preend,inorder,inrootpos+1,inend);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return solve(preorder,0,n-1,inorder,0,n-1);
    }
};
