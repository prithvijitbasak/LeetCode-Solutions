//Editorial: https://leetcode.com/problems/evaluate-reverse-polish-notation/solutions/47544/challenge-me-neat-c-solution-could-be-simpler/?orderBy=most_votes
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto it:tokens)
        {
            string s=it;
            if(s.size()>1 or isdigit(s[0])) //The s.size() > 1, accounts for negative numbers, because there the first character will be a minus not a digit.
                stk.push(stoi(s));
            else
            {
                char ch=it[0];
                long long int s=stk.top();
                stk.pop();
                long long int f=stk.top();
                stk.pop();
                if(ch=='*')
                    f*=s;
                if(ch=='/')
                    f/=s;
                if(ch=='-')
                    f-=s;
                if(ch=='+')
                    f+=s;
                stk.push(f);
            } 
        }
        return stk.top();
    }
};
