//Editorial: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/295163/C++-5-lines.-use-string-as-a-stack.
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(auto it:s)
        {
            if(ans.size() and ans.back()==it)
                ans.pop_back();
            else
                ans+=it;
        }
        return ans;
    }
};
