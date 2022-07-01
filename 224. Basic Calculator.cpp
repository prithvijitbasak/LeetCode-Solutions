//Editorial: https://leetcode.com/problems/basic-calculator/discuss/62361/Iterative-Java-solution-with-stack
class Solution {
public:
    int calculate(string s) {
        int ans=0;
        stack<int> stk;
        int n=s.size();
        int sign=1,val=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' and s[i]<='9')
                val=val*10+(int)(s[i]-'0');
            else if(s[i]=='+')
            {
                ans+=sign*val;
                sign=1;
                val=0;
            }
            else if(s[i]=='-')
            {
                ans+=sign*val;
                sign=-1;
                val=0;
            }
            else if(s[i]=='(')
            {
                stk.push(ans);
                stk.push(sign);
                sign=1;
                ans=0;
            }
            else if(s[i]==')')
            {
                ans+=sign*val;
                val=0;
                ans*=stk.top();
                stk.pop();
                ans+=stk.top();
                stk.pop();
            }
        }
        if(val)
            ans+=sign*val;
        return ans;
    }
};
