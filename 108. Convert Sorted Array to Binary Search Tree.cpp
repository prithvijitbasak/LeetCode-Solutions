//Editorial: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/35220/My-Accepted-Java-Solution
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
    TreeNode* solve(vector<int> nums,int low,int high)
    {
        if(low>high)
            return nullptr;
        int mid=low+(high-low)/2;
        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=solve(nums,low,mid-1);
        curr->right=solve(nums,mid+1,high);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        int n=nums.size();
        root=solve(nums,0,n-1);
        return root;
    }
};
