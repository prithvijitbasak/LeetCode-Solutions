//Editorial: https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100
class Solution {
public:
    unordered_map<char,char> ump;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<size(order);i++)
            ump[order[i]]=i+'a';
        for(auto &it:words)
        {
            for(char &ch:it)
                ch=ump[ch];
        }
        return is_sorted(words.begin(),words.end());
    }
};
