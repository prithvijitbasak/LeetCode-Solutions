//Approach 1: Using binary search. TC: O(nlogn) SC: O(1).
//Editorial: https://leetcode.com/problems/search-suggestions-system/discuss/436126/C++-Easy-sort-(No-trie)-O(1)-Space
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string word) {
        sort(products.begin(),products.end());
        int start=0;
        int n=word.size();
        string curr;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            curr+=word[i];
            int idx=lower_bound(products.begin()+start,products.end(),curr)-products.begin();
            ans.push_back({});
            for(int j=idx;j<min(idx+3,(int)products.size()) and !products[j].compare(0,curr.size(),curr);j++)
                ans.back().push_back(products[j]);
            start=idx;
        }
        return ans;
    }
};
//Approach 2: Using trie.
//Editorial: https://leetcode.com/problems/search-suggestions-system/discuss/442359/C++-Three-Way-Solution-With-Picturearrary-sort-Trie(hash+array)Trie(hash+heap))
class Solution {
public:
    struct Trie {
        unordered_map<char,Trie*> ump={};
        priority_queue<string> suggest={};
    };
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *root=new Trie();
        for(auto word:products)
        {
            Trie *temp=root;
            for(auto it:word)
            {
                if(!temp->ump.count(it))
                    temp->ump[it]=new Trie();
                temp=temp->ump[it];
                temp->suggest.push(word);
                if(temp->suggest.size()>3)
                    temp->suggest.pop();
            }
        }
        vector<vector<string>> ans(searchWord.size());
        for(int i=0;i<searchWord.size() and root->ump.count(searchWord[i]);i++)
        {
            root=root->ump[searchWord[i]];
            vector<string> match(root->suggest.size());
            for(int i=root->suggest.size()-1;i>=0;i--)
            {
                match[i]=root->suggest.top();
                root->suggest.pop();
            }
            ans[i]=match;
        }
        return ans;
    }
};
