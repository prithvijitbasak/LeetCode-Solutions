//Editorial: Learn about the KMP algorithm first then try to solve it (https://youtu.be/4jY57Ehc14Y) , https://leetcode.com/problems/longest-happy-prefix/solutions/547204/c-kmp-preprocessing/?orderBy=most_votes
class Solution {
public:
    vector<int> solve(string s)
    {
        int n=s.size();
        vector<int> lps(n,0);
        int len=0;
        for(int i=1;i<n;)
        {
            if(s[i]==s[len])
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
                {
                    lps[i]=0;
                    i+=1;
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int> lps=solve(s);
        return s.substr(0,lps.back());
    }
};
