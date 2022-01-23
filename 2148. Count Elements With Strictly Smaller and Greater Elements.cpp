//Editorial: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/discuss/1711307/C%2B%2B-or-O(N)-Time-or-O(1)-Space-or-100-Efficient
class Solution {
public:
    int countElements(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[0] and nums[i]<nums[n-1])
                cnt++;
        }
        return cnt;
    }
};
