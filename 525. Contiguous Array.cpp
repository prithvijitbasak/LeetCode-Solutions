//Editorial: https://leetcode.com/problems/contiguous-array/discuss/1743341/C%2B%2B-Simplest-Solution-or-Optimization-from-Brute-Force-or-One-Pass
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> ump{{0,-1}};
        int sum=0,mxans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==1?1:-1;
            if(ump.count(sum))
                mxans=max(mxans,i-ump[sum]);
            else
                ump[sum]=i;
        }
        return mxans;
    }
};
