//Editorial: https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100
class Solution {
public:
    unordered_map<char,int> mp;
    bool checkorder(string a,string b)
    {
        int i=0;
        while(i++<a.size() and i<b.size())
        {
            if(mp[a[i]]!=mp[b[i]])
                return mp[a[i]]<mp[b[i]];
        }
        return size(a)<=size(b);
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            if(!checkorder(words[i],words[i+1]))
                return false;
        }
        return true;
    }
};
