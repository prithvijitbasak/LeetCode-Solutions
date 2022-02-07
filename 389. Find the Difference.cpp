//Editorial: https://leetcode.com/problems/find-the-difference/discuss/86826/Concise-C%2B%2B-solution-using-XOR
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch=0;
        for(auto it:s)
            ch^=it;
        for(auto it:t)
            ch^=it;
        return ch;
    }
};
