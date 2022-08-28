//Editorial: https://leetcode.com/problems/removing-stars-from-a-string/discuss/2493117/JavaC++Python-Stack-Simulation
class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(auto it:s)
        {
            if(it=='*')
                ans.pop_back();
            else
                ans+=it;
        }
        return ans;
    }
};
