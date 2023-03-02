//Editorial 1: https://leetcode.com/problems/excel-sheet-column-number/discuss/52154/Concise-java-solution-with-explanation.
//Editorial 2: https://leetcode.com/problems/excel-sheet-column-title/solutions/441430/detailed-explanation-here-s-why-we-need-n-at-first-of-every-loop-java-python-c/?orderBy=most_votes
class Solution {
public:
    int titleToNumber(string s) {
        //for String ABZ and its corresponding number n:
        //n = (A+1) * 26^2 + (B+1) * 26^1 + (Z+1) * 26^0
        int n=s.size();
        int j=n-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(s[i]-'A'+1)*pow(26,j);
            j-=1;
        }
        return ans;
    }
};
