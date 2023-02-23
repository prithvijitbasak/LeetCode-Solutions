//Editorial: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/solutions/3203994/java-c-python-1-line-solution/?orderBy=most_votes
class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        while(n)
        {
            if((n&3)==3)
            {
                n+=1;
                ans+=1;
            }
            else
            {
                ans+=n&1;
                n>>=1;
            }
        }
        return ans;
    }
};
