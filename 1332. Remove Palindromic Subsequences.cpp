//Editorial: https://leetcode.com/problems/remove-palindromic-subsequences/discuss/490352/Java-Use-the-Trick-:-the-input-string-only-consists-of-letters-'a'-and-'b'!!
class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return 2;
        }
        return 1;
    }
};
