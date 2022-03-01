//Editorial: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/discuss/1108695/Java-100-faster-runtime-memory-I-bet-the-easiest-to-understand/905903
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x=-1,y=-1;
        for(int i=0;i<s1.size();i++)
        {
            char ch1=s1[i],ch2=s2[i];
            if(ch1!=ch2)
            {
                if(x==-1)
                    x=i;
                else if(y==-1)
                    y=i;
                else
                    return false;
            }
        }
        if(x==-1)
            return true;
        else if(y==-1)
            return false;
        return s1[x]==s2[y] and s1[y]==s2[x];
    }
};
