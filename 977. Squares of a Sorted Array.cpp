//Editorial: https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int l=0,r=n-1;
        for(int j=n-1;j>=0;j--)
        {
            if(abs(nums[l])>abs(nums[r]))
            {
                ans[j]=nums[l]*nums[l];
                l++;
            }
            else
            {
                ans[j]=nums[r]*nums[r];
                r--;
            }
        }
        return ans;
    }
};
