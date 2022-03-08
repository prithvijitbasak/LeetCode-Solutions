//Editorial: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/discuss/736309/C%2B%2B-0ms-solution
class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string ans="";
        int i=0;
        while(i<n)
        {
            if(i+2<n and s[i+2]=='#')
            {
                int num=(s[i]-'0')*10+(s[i+1]-'0');
                ans+=(num+96);
                i+=3;
            }
            else
            {
                ans+=(s[i]-'0')+96;
                i+=1;
            }
        }
        return ans;
    }
};
