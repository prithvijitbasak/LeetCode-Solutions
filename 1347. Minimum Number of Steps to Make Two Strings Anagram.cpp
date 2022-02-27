//Editorial: Just using hashing we can find how many characters to be replaced.
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(auto it:s)
            freq[it-'a']+=1;
        for(auto ch:t)
            freq[ch-'a']-=1;
        int ans=0;
        for(auto it:freq)
        {
            if(it<0)
                ans+=it;
        }
        return abs(ans);
    }
};
