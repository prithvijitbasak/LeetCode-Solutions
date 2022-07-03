//Editorial: https://leetcode.com/problems/rearrange-array-elements-by-sign/discuss/1711413/C++-oror-two-pointer-oror-O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int indpos=0,indneg=1;
        for(auto it:nums)
        {
            if(it>0)
            {
                ans[indpos]=it;
                indpos+=2;
            }
            else
            {
                ans[indneg]=it;
                indneg+=2;
            }
        }
        return ans;
    }
};
