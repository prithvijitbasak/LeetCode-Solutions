//Editorial: https://leetcode.com/problems/length-of-last-word/discuss/21892/7-lines-4ms-C++-Solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int tail=n-1;
        while(tail>=0 and s[tail]==' ')
        {
            tail--;
        }
        int len=0;
        while(tail>=0 and s[tail]!=' ')
        {
            len+=1;
            tail--;
        }
        return len;
    }
};
