//Approach 1: Using stack. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/construct-smallest-number-from-di-string/discuss/2422180/C++-Clean-Stack-Solution
class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int> stk;
        string ans="";
        for(int i=0;i<=n;i++)
        {
            stk.push(i+1);
            if(i==n or pattern[i]=='I')
            {
                while(!stk.empty())
                {
                    ans+=to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return ans;
    }
};
//Approach 2: Using reverse function. TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/construct-smallest-number-from-di-string/discuss/2422290/DFS-vs.-Greedy
class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        int n=pattern.size();
        for(int i=0,j=0;i<=n;i++)
        {
            ans+=(i+'1');
            if(i==n or pattern[i]=='I')
            {
                reverse(ans.begin()+j,ans.end());
                j=i+1;
            }
        }
        return ans;
    }
};
