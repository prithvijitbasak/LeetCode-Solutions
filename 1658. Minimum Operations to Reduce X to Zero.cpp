//Editorial: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/935935/Java-Detailed-Explanation-O(N)-Prefix-SumMap-Longest-Target-Sub-Array
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=-x;
        for(auto it:nums)
            target+=it;
        int n=nums.size();
        if(target==0)
            return n;
        map<int,int> mp;
        mp[0]=-1;
        int sum=0,ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end())
                ans=max(ans,i-mp[sum-target]);
            mp[sum]=i;
        }
        return ans==INT_MIN?-1:n-ans;
    }
};
