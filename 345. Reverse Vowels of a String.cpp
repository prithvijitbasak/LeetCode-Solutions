//Editorial: Just iterate over the string and store the vowels to reverse and to the answer variable.
class Solution {
public:
    string reverseVowels(string s) {
        string ans="";
        string rev="";
        set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        for(auto it:s)
        {
            if(st.find(it)!=st.end())
            {
                ans+='*';
                rev+=it;
            }
            else
                ans+=it;
        }
        reverse(rev.begin(),rev.end());
        int i=0;
        for(auto &it:ans)
        {
            if(it=='*')
            {
                it=rev[i];
                i++;
            }
        }
        return ans;
    }
};
