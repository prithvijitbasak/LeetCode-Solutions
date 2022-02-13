//Method 1: Using stringstream.
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word)
        {
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=" ";
        }
        return ans.substr(0,ans.size()-1);
    }
};
// Method 2: In-place reversing.
class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                int j=i;
                for(;j<s.size() and s[j]!=' ';j++) {}
                reverse(s.begin()+i,s.begin()+j);
                i=j-1;
            }
        }
        return s;
    }
};
