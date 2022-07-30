//Editorial: https://leetcode.com/problems/word-subsets/discuss/1128123/Short-and-Easy-w-Explanation-or-O(A-+-B)-using-max-frequency-count-or-Beats-100
class Solution {
public:
    vector<int> count(string s)
    {
        vector<int> freq(26);
        for(auto it:s)
            freq[it-'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxfreq(26);
        for(auto it:words2)
        {
            string s=it;
            vector<int> freq=count(s);
            for(int i=0;i<26;i++)
                maxfreq[i]=max(freq[i],maxfreq[i]);
        }
        vector<string> ans;
        for(auto it:words1)
        {
            vector<int> freq=count(it);
            int i=0;
            for(;i<26;i++)
            {
                if(freq[i]<maxfreq[i])
                    break;
            }
            if(i==26)
                ans.push_back(it);
        }
        return ans;
    }
};
