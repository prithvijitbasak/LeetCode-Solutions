//Editorial: https://leetcode.com/problems/string-to-integer-atoi/discuss/1402936/JAVA-C%2B%2B-%3A-Simple-or-Easy-or-32-bit-int-or-Faster-than-100-or-Explained
class Solution {
public:
    int myAtoi(string s) {
        int isneg=0;
        int idx=0,n=s.size();
        while(idx<n and s[idx]==' ')
            idx++;
        if(idx<n)
        {
            if(s[idx]=='-')
            {
                isneg=1;
                idx++;
            }
            else if(s[idx]=='+')
                idx++;
            
        }
        int ans=0;
        while(idx<n and isdigit(s[idx]))
        {
            int digit=s[idx]-'0';
            if(ans>INT_MAX/10 or(ans==INT_MAX/10 and digit>7))
                return (isneg)?INT_MIN:INT_MAX;
            ans=(ans*10)+digit;
            idx++;
        }
        return (isneg)?-ans:ans;
    }
    int isdigit(char ch)
    {
        if(ch>='0' and ch<='9')
            return 1;
        return 0;
    }
};
