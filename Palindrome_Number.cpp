class Solution {
public:
    bool isPalindrome(int x) {
        string s1,s2;
        s1=to_string(x);
        s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};
