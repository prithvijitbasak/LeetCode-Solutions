//Editorial: https://leetcode.com/problems/make-the-string-great/discuss/2790806/C++-Easy-or-One-pass-or-O(n)-Space
class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            ans+=s[i];
            while(ans.size() and (ans.back()==s[i+1]+32 or ans.back()==s[i+1]-32))
            {
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};
