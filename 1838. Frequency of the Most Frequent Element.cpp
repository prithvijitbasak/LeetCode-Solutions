//Editorial: https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,i=0;
        long sum=0;
        int n=nums.size();
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            while(sum+k<((j-i+1)*(long)nums[j]))
                sum-=nums[i++];
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
