//Editorial: https://leetcode.com/problems/longest-common-prefix/discuss/391089/C%2B%2B-Easy-to-understand-solution-%3A-Using-sort
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string ans="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string s=strs[0],e=strs[n-1];
        for(int i=0;i<s.size();i++)
        {
            if(e[i]==s[i])
                ans+=s[i];
            else
                break;
        }
        return ans;
    }
};
