//Editorial: https://leetcode.com/problems/backspace-string-compare/solution/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1,j=t.size()-1;
        int skips=0,skipt=0;
        while(i>=0 or j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    skips+=1;
                    i--;
                }
                else if(skips>0)
                {
                    skips-=1;
                    i-=1;
                }
                else
                    break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    skipt+=1;
                    j--;
                }
                else if(skipt>0)
                {
                    skipt-=1;
                    j--;
                }
                else
                    break;
            }
            if(i>=0 and j>=0 and s[i]!=t[j])
                return false;
            if((i>=0)!=(j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};
