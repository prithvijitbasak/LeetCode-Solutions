//Editorial: https://leetcode.com/problems/greatest-common-divisor-of-strings/solutions/3024822/greatest-common-divisor-of-strings/?orderBy=most_votes
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        int m=str1.size(),n=str2.size();
        if(str1+str2!=str2+str1)
            return "";
        int gcdlen=__gcd(m,n);
        return str1.substr(0,gcdlen);
    }
};
