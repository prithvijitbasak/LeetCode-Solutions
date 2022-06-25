//Editorial: https://leetcode.com/problems/non-decreasing-array/discuss/106826/JavaC++-Simple-greedy-like-solution-with-explanation
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                cnt+=1;
                if(i-2<0 or nums[i-2]<=nums[i])
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
            }
        }
        return cnt<=1;
    }
};
