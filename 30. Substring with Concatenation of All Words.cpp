//Editorial: https://youtu.be/Bbu4Qjzf7A0
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        unordered_map<string,int> count,temp;
        for(string it:words)
            count[it]++;
        int n=s.size(),eachwordlen=words[0].size();
        int totalword=words.size();
        for(int i=0;i<=n-totalword*eachwordlen;i++)
        {
            for(int j=i;j<i+totalword*eachwordlen;j+=eachwordlen)
            {
                string word=s.substr(j,eachwordlen);
                temp[word]++;
            }
            int ok=1;
            for(auto it:count)
            {
                if(temp[it.first]!=it.second)
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                ans.push_back(i);
            temp.clear();
        }
        return ans;
    }
};
