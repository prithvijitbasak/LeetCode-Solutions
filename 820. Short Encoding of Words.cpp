//Approach 1: Storing prefixes in set. TC: O(sumof(words)^2) SC: O(sumof(words)).
//Editorial: https://leetcode.com/problems/short-encoding-of-words/solution/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st;
        for(auto it:words)
            st.insert(it);
        for(auto it:words)
        {
            for(int i=1;i<it.size();i++)
                st.erase(it.substr(i));
        }
        int ans=0;
        for(auto it:st)
            ans+=it.size()+1;
        return ans;
    }
};
//Approach 2: Using trie. 
//Editorial: https://leetcode.com/problems/short-encoding-of-words/discuss/1095894/JS-Python-Java-C++-or-(Updated)-Set-and-Trie-Solutions-w-Visual-Explanation
struct Node {
    Node* links[26];
    bool isempty=true;
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Node* root=new Node();
        int ans=1;
        for(auto it:words)
        {
            Node* curr=root;
            bool newword=false;
            for(int i=it.size()-1;i>=0;i--)
            {
                int val=it[i]-'a';
                if(curr->isempty and !newword)
                    ans-=it.size()-i;
                if(!curr->links[val])
                {
                    curr->links[val]=new Node();
                    newword=true;
                    curr->isempty=false;
                }
                curr=curr->links[val];
            }
            if(newword)
                ans+=it.size()+1;
        }
        return ans;
    }
};
