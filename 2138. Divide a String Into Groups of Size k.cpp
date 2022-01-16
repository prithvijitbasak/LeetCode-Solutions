//Editorial: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/discuss/1693253/Division-and-Modulo
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string str="";
        vector<string> ans;
        for(int i=0;i<s.size();i++)
        {
            if(str.size()==k)
            {
                ans.push_back(str);
                str.clear();
            }
            str+=s[i];
        }
        
        if(str.size()!=k)
            while(str.size()!=k)
                str+=fill;
        ans.push_back(str);
        return ans;
    }
};
