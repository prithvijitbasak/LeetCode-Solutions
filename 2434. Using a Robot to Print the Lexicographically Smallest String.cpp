//Editorial: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/discuss/2678848/Stack-it-Up-!!-Easy-to-understand-c++
class Solution {
public:
    char lowest(vector<int> &freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                return i+'a';
        }
        return 'a';
    }
    string robotWithString(string s) {
        string ans="";
        stack<char> stk;
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']+=1;
        for(auto it:s)
        {
            stk.push(it);
            freq[it-'a']-=1;
            while(!stk.empty() and stk.top()<=lowest(freq))
            {
                char ch=stk.top();
                ans+=ch;
                stk.pop();
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
