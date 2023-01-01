//Editorial: https://leetcode.com/problems/word-pattern/solutions/73409/short-c-read-words-on-the-fly/?orderBy=most_votes
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> ump1;
        unordered_map<string,int> ump2;
        stringstream str(s);
        string temp;
        int i=0,n=pattern.size();
        for(;str>>temp;i++)
        {
            if(i==n or ump1[pattern[i]]!=ump2[temp])
                return false;
            ump1[pattern[i]]=i+1;
            ump2[temp]=i+1;
        }
        return i==n;
    }
};
