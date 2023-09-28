// Editorial: Read the code comments.
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // vector for answer output
        vector<string> ans;
        // this map is used to store the frequency of first word in words
        map<char,int> mp1;
        for(auto it:words[0])
            mp1[it] += 1;
        // set<pair<char,int>> st;
        for(auto word:words)
        {
            // this map is for the frequency of other words except the-first
            map<char,int> mp2;
            for(char ch:word)
                mp2[ch] += 1;
        // here we are checking if the frequency of any other word 
        // is more or less than the frequency in the first word
        // then we will only take the minimum because we need to take the
        // common elements among them.
            for(auto it:mp1)
            {
                if(it.second != mp2[it.first])
                    mp1[it.first] = min(it.second, mp2[it.first]);
            }
        }
        for(auto it:mp1)
        {
            int t = it.second;
            while(t--)
            {
                stringstream ss;
                ss << it.first;
                string val;
                val = ss.str();
                ans.push_back(val);
            }
        }
        return ans;
    }
};
