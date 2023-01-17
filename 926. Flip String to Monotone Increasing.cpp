//Editorial: https://leetcode.com/problems/flip-string-to-monotone-increasing/solutions/2912351/flip-string-to-monotone-increasing/?orderBy=most_votes
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num=0,ans=0;
        for(auto it:s)
        {
            if(it=='0')
                ans=min(num,ans+1);
            else
                num+=1;
        }
        return ans;
    }
};
