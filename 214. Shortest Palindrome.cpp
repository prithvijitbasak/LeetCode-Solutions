//Editorial: https://leetcode.com/problems/shortest-palindrome/editorial
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string str=s+'#';
        string rev=s;
        reverse(rev.begin(),rev.end());
        str+=rev;
        int sz=str.size();
        vector<int> lps(sz,0);
        int len=0;
        for(int i=1;i<sz;)
        {
            if(str[i]==str[len])
            {
                len+=1;
                lps[i]=len;
                i+=1;
            }
            else
            {
                if(len!=0)
                    len=lps[len-1];
                else
                    i+=1;
            }
        }
        int val=lps[sz-1];
        string req=rev.substr(0,n-val);
        return req+s;
    }
};
