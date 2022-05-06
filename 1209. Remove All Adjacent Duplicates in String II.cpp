//Editorial: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/1995282/c++-oror-stack-based-solution
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        int n=s.size();
        if(n<k)
            return s;
        for(int i=0;i<n;i++)
        {
            if(stk.empty() or stk.top().first!=s[i])
                stk.push({s[i],1});
            else
            {
                auto prev=stk.top();
                stk.pop();
                stk.push({s[i],prev.second+1});
            }
            if(stk.top().second==k)
                stk.pop();
        }
        string ans="";
        while(!stk.empty())
        {
            auto curr=stk.top();
            stk.pop();
            while(curr.second--)
            {
                ans+=curr.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
