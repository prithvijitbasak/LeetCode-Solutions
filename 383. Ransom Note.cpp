//Editorial: https://leetcode.com/problems/ransom-note/discuss/85783/Java-O(n)-Solution-Easy-to-understand
class Solution {
public:
    bool canConstruct(string ransomenote, string magazine) {
        vector<int> freq(26);
        for(int i=0;i<magazine.size();i++)
            freq[magazine[i]-'a']+=1;
        for(int i=0;i<ransomenote.size();i++)
        {
            if(--freq[ransomenote[i]-'a']<0)
                return false;
        }
        return true;
    }

};
