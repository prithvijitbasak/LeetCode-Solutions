//Editorial: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/discuss/2039931/2-Pointers-oror-Without-sorting
class Solution {
public:
    bool isanag(string a,string b)
    {
        vector<int> freq(26);
        for(auto it:a)
            freq[it-'a']+=1;
        for(auto it:b)
            freq[it-'a']-=1;
        for(auto it:freq)
        {
            if(it)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        for(int i=0;i<n;)
        {
            int j=i+1;
            while(j<n and isanag(words[i],words[j]))
                j+=1;
            ans.push_back(words[i]);
            i=j;
        }
        return ans;
    }
};
