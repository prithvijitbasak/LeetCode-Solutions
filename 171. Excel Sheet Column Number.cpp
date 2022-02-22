//Editorial: https://leetcode.com/problems/excel-sheet-column-number/discuss/52154/Concise-java-solution-with-explanation.
class Solution {
public:
    int titleToNumber(string s) {
        // Suppose the test case is "BCM"
        // then the solution is 
        //     "B" = 2
        //     "BC" = (2)26 + 3
        //     "BCM" = (2(26) + 3)26 + 13
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans*=26;
            ans+=s[i]-64;
        }
        return ans;
    }
};
