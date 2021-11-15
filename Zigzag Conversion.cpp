//Editorial: https://leetcode.com/problems/zigzag-conversion/discuss/3417/A-10-lines-one-pass-o(n)-time-o(1)-space-accepted-solution-with-detailed-explantation
class Solution {
public:
    string convert(string s, int rows) {
        string ans="";
        int n=s.size();
        if(rows<=1)
            return s;
        int cycle=2*rows-2;
        for(int i=0;i<rows;i++)
        {
            for(int j=i;j<s.size(); j+=cycle)
            {
                ans+=s[j];
                int sj=(j-i)+cycle-i;
                if(i!=0 and i!=rows-1 and sj<n)
                    ans+=s[sj];
            }
        }
        return ans;
    }
};
