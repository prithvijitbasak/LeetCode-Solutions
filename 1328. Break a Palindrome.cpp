//Editorial: https://leetcode.com/problems/break-a-palindrome/discuss/489774/JavaC++Python-Easy-and-Concise
class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';
                return s;
            }
        }
        s[n-1]='b';
        return n<2 ? "" : s;
    }
};
