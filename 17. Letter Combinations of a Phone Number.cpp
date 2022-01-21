//Editorial: https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8090/Iterative-c%2B%2B-solution-in-0ms
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> maps={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.empty())
            return ans;
        ans.push_back("");
        for(auto it:digits)
        {
            vector<string> temp;
            for(auto combi:maps[it-'0'])
            {
                for(auto ch:ans)
                    temp.push_back(ch+combi);
            }
            ans.swap(temp);
        }
        return ans;
    }
};
