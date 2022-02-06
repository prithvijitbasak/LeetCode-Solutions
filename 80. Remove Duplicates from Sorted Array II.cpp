//Editorial: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27970/Share-my-O(N)-time-and-O(1)-solution-when-duplicates-are-allowed-at-most-K-times/27014
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int incount=1,n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                incount++;
                if(incount>2)
                    continue;
            }
            else
                incount=1;
            nums[count++]=nums[i];
        }
        return count;
    }
};
