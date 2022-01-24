//Editorial: Very basic problem. Just go through the solution to get more clarity.
class Solution {
public:
    bool detectCapitalUse(string s) {
        int fc=0,capcnt=0;
        if(s[0]>='A' and s[0]<='Z')
        {
            capcnt+=1;
            fc=1;
        }
        for(int i=1;i<s.size();i++)
        {
            if(s[i]>='A' and s[i]<='Z')
            {
                capcnt+=1;
            }
        }
        if(capcnt==s.size())
            return true;
        else if(capcnt==1 and fc)
            return true;
        else if(capcnt==0)
            return true;
        else
            return false;
    }
};
