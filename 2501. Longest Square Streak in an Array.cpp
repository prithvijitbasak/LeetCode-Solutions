//Editorial: https://leetcode.com/problems/longest-square-streak-in-an-array/solutions/2899678/short-dp-c-java-lis-type/?orderBy=most_votes
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> dp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int root=sqrt(nums[i]);
            if(root*root==nums[i])
                dp[nums[i]]=1+dp[root];
            else
                dp[nums[i]]=1;
            ans=max(ans,dp[nums[i]]);
        }
        return ans<2?-1:ans;
    }
};
