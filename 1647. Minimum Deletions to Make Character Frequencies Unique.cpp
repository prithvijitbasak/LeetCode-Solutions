//Editorial: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solution/
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']+=1;
        sort(freq.rbegin(),freq.rend());
        int maxfreqal=s.size(),ans=0;
        for(int i=0;i<26 and freq[i]>0; i++)
        {
            if(freq[i]>maxfreqal)
            {
                ans+=freq[i]-maxfreqal;
                freq[i]=maxfreqal;
            }
            maxfreqal=max(0,freq[i]-1);
        }
        return ans;
    }
};
