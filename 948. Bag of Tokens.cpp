//Editorial: https://leetcode.com/problems/bag-of-tokens/discuss/197696/C++JavaPython-Greedy-+-Two-Pointers
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int ans=0,score=0,i=0,j=n-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                score+=1;
                ans=max(ans,score);
                i++;
            }
            else if(score>0)
            {
                score-=1;
                power+=tokens[j];
                j--;
            }
            else
                break;
        }
        return ans;
    }
};
