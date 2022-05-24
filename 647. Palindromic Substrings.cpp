//Editorial: https://leetcode.com/problems/palindromic-substrings/discuss/105691/JavaC%2B%2B-6-lines-solution-NO-DP
class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;i-j>=0 and i+j<n and s[i-j]==s[i+j];j++)
                ans+=1;
            for(int j=0;i-j-1>=0 and i+j<n and s[i-j-1]==s[i+j];j++)
                ans+=1;
        }
        return ans;
    }
};
