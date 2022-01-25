//Editorial: https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack/243370
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            else
            {
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else
                    ans=max(ans,i-stk.top());
            }
        }
        return ans;
    }
};
