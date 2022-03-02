//Editorial: https://leetcode.com/problems/is-subsequence/discuss/678426/C%2B%2B-3-Approaches-1.-Recursion-2.-Two-Pointer-3.-Dynamic-Programming
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(s[i]==t[j])
                i++;
            j++;
        }
        if(i==m)
            return true;
        return false;
    }
};
