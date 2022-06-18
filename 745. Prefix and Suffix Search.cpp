//Editorial: https://leetcode.com/problems/prefix-and-suffix-search/discuss/1185249/C++-No-TRIE-A-HashMap-soln.
class WordFilter {
public:
    unordered_map<string,int> ump;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string temp=words[i];
            int sz=temp.size();
            for(int j=1;j<=sz;j++)
            {
                string prefix=temp.substr(0,j);
                for(int k=0;k<sz;k++)
                {
                    string suffix=temp.substr(k,sz);
                    ump[prefix+"#"+suffix]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"#"+suffix;
        if(ump.find(s)==ump.end())
            return -1;
        return ump[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
