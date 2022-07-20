//Editorial: https://leetcode.com/problems/number-of-matching-subsequences/discuss/1289527/Number-of-Matching-Subsequences-or-Easy-Solution-w-Explanation-or-Binary-Search
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> nums(26);
        int n=s.size();
        for(int i=0;i<n;i++)
            nums[s[i]-'a'].push_back(i);
        int ans=0;
        for(auto it:words)
        {
            int prev=-1,f=1;
            for(auto ch:it)
            {
                auto idx=upper_bound(nums[ch-'a'].begin(),nums[ch-'a'].end(),prev);
                if(idx==nums[ch-'a'].end())
                {
                    f=0;
                    break;
                }
                else
                    prev=*idx;
            }
            if(f)
                ans+=1;
        }
        return ans;
    }
};
