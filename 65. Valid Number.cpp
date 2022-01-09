//Editorial: https://youtu.be/0qac3ngAZmE
class Solution {
public:
    bool isNumber(string s) {
        int digitseen=0,eseen=0,dotseen=0;
        int cntplusminus=0;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(isdigit(ch))
                digitseen=1;
            else if(ch=='+' or ch=='-')
            {
                if(cntplusminus==2)
                    return false;
                if(i>0 and (s[i-1]!='e' and s[i-1]!='E'))
                    return false;
                if(i==s.size()-1)
                    return false;
                cntplusminus++;
            }
            else if(ch=='.')
            {
                if(eseen or dotseen)
                    return false;
                if(i==s.size()-1 and !digitseen)
                    return false;
                dotseen=1;
            }
            else if(ch=='e' or ch=='E')
            {
                if(eseen or !digitseen or i==s.size()-1)
                    return false;
                eseen=1;
            }
            else
                return false;
        }
        return true;
    }
};
