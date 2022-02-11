//Editorial: https://leetcode.com/problems/permutation-in-string/discuss/357821/C%2B%2B-Concise-Solution
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> curr(26),req(26);
        for(auto it:s1)
            req[it-'a']++;
        for(int j=0;j<s2.size();j++)
        {
            curr[s2[j]-'a']++;
            if(j>=s1.size())
                curr[s2[j-s1.size()]-'a']--;
            if(curr==req)
                return true;
        }
        return false;
    }
};
