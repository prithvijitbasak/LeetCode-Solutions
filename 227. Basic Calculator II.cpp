//Editorial: https://leetcode.com/problems/basic-calculator-ii/solutions/63006/c-stack-solution/?orderBy=most_votes
class Solution {
public:
    int calculate(string s) {
        int ans=0;
        char sign='+';
        int val=0;
        int n=s.size();
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' and s[i]<='9')
                val=(val*10)+(s[i]-'0');
            if((!isdigit(s[i]) and !isspace(s[i])) or i==n-1)
            {
                if(sign=='+')
                    stk.push(val);
                else if(sign=='-')
                    stk.push(-val);
                else if(sign=='*')
                {
                    int num=stk.top();
                    stk.pop();
                    stk.push(num*val);
                }
                else if(sign=='/')
                {
                    int num=stk.top();
                    stk.pop();
                    stk.push(num/val);
                }
                sign=s[i];
                val=0;
            }
        }
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};
