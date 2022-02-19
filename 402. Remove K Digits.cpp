//Editorial: https://youtu.be/3QJzHqNAEXs
class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> stk;
        for(char ch:s)
        {
            while(!stk.empty() and k>0 and stk.top()>ch)
            {
                stk.pop();
                k--;
            }
            if(!stk.empty() or ch!='0')
                stk.push(ch);
        }
        while(!stk.empty() and k--)
            stk.pop();
        if(stk.empty())
            return "0";
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
