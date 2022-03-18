//Editorial: https://leetcode.com/problems/remove-duplicate-letters/discuss/76769/Java-solution-using-Stack-with-comments
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<int> vis(26,0);
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']++;
        for(auto it:s)
        {
            freq[it-'a']--;
            if(vis[it-'a'])
                continue;
            while(!stk.empty() and it<stk.top() and freq[stk.top()-'a']!=0)
            {
                char ch=stk.top();
                stk.pop();
                vis[ch-'a']=0;
            }
            stk.push(it);
            vis[it-'a']=1;
        }
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
