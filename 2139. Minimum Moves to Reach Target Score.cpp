//Editorial: https://leetcode.com/problems/minimum-moves-to-reach-target-score/discuss/1692912/Go-Backwards
class Solution {
public:
    int minMoves(int target, int d) {
        int ans=0;
        while(target>1)
        {
            if(d<=0)
                break;
            if(target%2==0 and d)
            {
                target/=2;
                d-=1;
                ans+=1;
            }
            else
            {
                target-=1;
                ans+=1;
            }
        }
        return ans+=target-1;
    }
};
