//Editorial: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC%2B%2B-Stack
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                stk.push(i);
            if(s[i]==')')
            {
                if(!stk.empty())
                    stk.pop();
                else
                    s[i]='*';
            }
        }
        while(!stk.empty())
        {
            s[stk.top()]='*';
            stk.pop();
        }
        string ans="";
        for(auto it:s)
        {
            if(it!='*')
                ans+=it;
        }
        return ans;
    }
};
