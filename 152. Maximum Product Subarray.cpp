//Editorial: https://leetcode.com/problems/maximum-product-subarray/discuss/183483/JavaC%2B%2BPython-it-can-be-more-simple
class Solution {
public:
    int maxProduct(vector<int>& nums){
        int left=0,right=0,ans=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            left=(left?left:1)*nums[i];
            right=(right?right:1)*nums[n-1-i];
            ans=max(ans,max(left,right));
        }
        return ans;
    }
};
