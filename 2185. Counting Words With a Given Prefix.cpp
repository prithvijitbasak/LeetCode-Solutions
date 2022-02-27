//Editorial: Very basic problem just take the size of the prefix and match the words with the size of prefix.
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            if(s.substr(0,n)==pref)
                cnt+=1;
        }
        return cnt;
    }
};
