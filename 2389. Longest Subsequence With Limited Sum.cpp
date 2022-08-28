//Editorial: https://leetcode.com/problems/longest-subsequence-with-limited-sum/discuss/2492718/C++-oror-Simple-oror-Easy-to-Understand
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> presum;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(auto it:nums)
        {
            sum+=it;
            presum.push_back(sum);
        }
        vector<int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(presum[j]<=queries[i])
                    ans[i]=j+1;
                else
                    break;
            }
        }
        return ans;
    }
};
