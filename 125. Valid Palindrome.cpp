// Editorial: Just traverse through the whole string and add all the alphabetic characters and numeric characters in one string then convert it
// to lower case then check is it is plaindromic or not.
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto it:s)
        {
            if((it>='A' and it<='Z') or (it>='a' and it<='z') or (it>='0' and it<='9'))
                str+=it;
        }
        transform(str.begin(),str.end(),str.begin(), ::tolower);
        string s1=str;
        reverse(s1.begin(),s1.end());
        return s1==str;
    }
};
