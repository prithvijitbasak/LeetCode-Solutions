//Editorial: https://leetcode.com/problems/longest-consecutive-sequence/discuss/1254638/Short-and-Easy-Solution-w-Explanation-or-O(N)-Solution-with-comments-using-hashset
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int ls=0,cs=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1)
                cs+=1;
            else
            {
                ls=max(ls,cs);
                cs=1;
            }
        }
        return max(ls,cs);
}
};
