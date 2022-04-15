//Editorial: https://leetcode.com/problems/valid-triangle-number/solution/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n-1 and nums[i];j++)
            {
                while(k<n and nums[i]+nums[j]>nums[k])
                    k++;
                cnt+=(k-j-1);
            }
        }
        return cnt;
    }
};
