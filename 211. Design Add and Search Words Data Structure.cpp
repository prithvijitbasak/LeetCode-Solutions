//Editorial: https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/1725030/C%2B%2B-oror-Easy-Explanation-oror-beat-100-solution
class WordDictionary {
    unordered_map<int,vector<string>> mp;
    bool isequal(string word1,string word2)
    {
        for(int i=0;i<word1.size();i++)
        {
            if(word2[i]=='.')
                continue;
            if(word1[i]!=word2[i])
                return false;
        }
        return true;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto it:mp[word.size()])
        {
            if(isequal(it,word))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
