//Editorial: https://leetcode.com/problems/reverse-words-in-a-string/discuss/1531693/C++-2-solutions-O(1)-space-Picture-explain-Clean-and-Concise/1452391
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,startindex=0,lastindex=0,n=s.size();
        reverse(s.begin(),s.end());
        while(j<n)
        {
            while(j<n and s[j]==' ')
                j++;
            startindex=i;
            while(j<n and s[j]!=' ')
            {
                s[i++]=s[j++];
                lastindex=i;
            }
            reverse(s.begin()+startindex,s.begin()+i);
            s[i++]=' ';
        }
        s.resize(lastindex);
        return s;
    }
};
