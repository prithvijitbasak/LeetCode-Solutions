//Editorial: https://leetcode.com/problems/isomorphic-strings/solution/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        vector<int> maps(256,-1);
        vector<int> mapt(256,-1);
        for(int i=0;i<n;i++)
        {
            char c1=s[i],c2=t[i];
            if(maps[c2]==-1 and mapt[c1]==-1)
            {
                maps[c2]=c1;
                mapt[c1]=c2;
            }
            else if(!(maps[c2]==c1 and mapt[c1]==c2))
                return false;
        }
        return true;
    }
};
