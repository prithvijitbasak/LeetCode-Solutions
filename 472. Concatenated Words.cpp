//Editorial: https://leetcode.com/problems/concatenated-words/solutions/2822170/concatenated-words/?orderBy=most_votes
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> ust(words.begin(),words.end());
        for(auto it:words)
        {
            int n=it.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=(i==n)?1:0;j<i;j++)
                {
                    if(dp[j] and ust.find(it.substr(j,i-j))!=ust.end())
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
            if(dp[n])
                ans.push_back(it);
        }
        return ans;
    }
};
