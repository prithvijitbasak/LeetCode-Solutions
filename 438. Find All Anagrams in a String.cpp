//Editorial: https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92027/C++-O(n)-sliding-window-concise-solution-with-explanation
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;
        if(s.size()<p.size())
            return ans;
        vector<int> freqs(26,0),freqp(26,0);
        for(int i=0;i<p.size();i++)
        {
            freqs[s[i]-'a']++;
            freqp[p[i]-'a']++;
        }
        if(freqp==freqs)
            ans.push_back(0);
        for(int i=p.size();i<s.size();i++)
        {
            freqs[s[i]-'a']++;
            freqs[s[i-p.size()]-'a']--;
            if(freqs==freqp)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
