//Editorial: https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)
            return ans;
        helper(ans,"",n,0);
        return ans;
    }
    void helper(vector<string> &ans,string s,int n,int m)
    {
        if(n==0 and m==0)
        {
            ans.push_back(s);
            return;
        }
        if(n>0)
        {
            helper(ans,s+"(",n-1,m+1);
        }
        if(m>0)
            helper(ans,s+")",n,m-1);
    }
};
