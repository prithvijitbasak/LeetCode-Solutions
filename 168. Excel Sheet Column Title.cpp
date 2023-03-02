//Editorial: https://leetcode.com/problems/excel-sheet-column-title/solutions/441430/detailed-explanation-here-s-why-we-need-n-at-first-of-every-loop-java-python-c/?orderBy=most_votes
class Solution {
public:
    string convertToTitle(int num) {
        string ans="";
        while(num)
        {
            num-=1;
            int rem=(num%26);
            char ch='A'+rem;
            ans+=ch;
            num/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
