//Edtorial: https://leetcode.com/problems/wiggle-subsequence/solution/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return n;
        int prevdiff=nums[1]-nums[0];
        int cnt=(prevdiff!=0)?2:1;
        for(int i=2;i<n;i++)
        {
            int diff=nums[i]-nums[i-1];
            if((diff<0 and prevdiff>=0) or (diff>0 and prevdiff<=0))
            {
                cnt+=1;
                prevdiff=diff;
            }
        }
        return cnt;
    }
};
