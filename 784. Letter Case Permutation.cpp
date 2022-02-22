//Editorial: https://leetcode.com/problems/letter-case-permutation/discuss/1068157/C%2B%2B-or-Recursion-or-O(2n)-0ms-Beats-100-or-Easy-to-Understand
class Solution {
public:
    void solve(int idx,string curr,vector<string> &ans,string s)
    {
        if(idx==s.size())
        {
            ans.push_back(curr);
            return;
        }
        if(isdigit(s[idx]))
        {
            curr.push_back(s[idx]);
            solve(idx+1,curr,ans,s);
        }
        else
        {
            string now1=curr;
            now1.push_back(tolower(s[idx]));
            solve(idx+1,now1,ans,s);
            string now2=curr;
            now2.push_back(toupper(s[idx]));
            solve(idx+1,now2,ans,s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(0,"",ans,s);
        return ans;
    }
};
