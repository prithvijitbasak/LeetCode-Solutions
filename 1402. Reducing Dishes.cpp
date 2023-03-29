//Editorial: https://leetcode.com/problems/reducing-dishes/editorial
//Approach 1: Using top-down dp. TC: O(n^2) SC: O(n^2).
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> satisfaction;
    int solve(int idx,int time)
    {
        if(idx==satisfaction.size())
            return 0;
        if(dp[idx][time]!=-1)
            return dp[idx][time];
        int cook=satisfaction[idx]*time+solve(idx+1,time+1);
        int skip=solve(idx+1,time);
        return dp[idx][time]=max(cook,skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        this->satisfaction=satisfaction;
        dp.resize(n+1,vector<int> (n+1,-1));
        return solve(0,1);
    }
};
//Approach 2: Using greedy technique.
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int suffixsum=0,maxsuffixsum=0;
        int time=1;
        for(int i=n-1;i>=0;i--)
        {
            suffixsum+=satisfaction[i];
            if(suffixsum<0)
                break;
            maxsuffixsum+=suffixsum;
        }
        return maxsuffixsum;
    }
};
