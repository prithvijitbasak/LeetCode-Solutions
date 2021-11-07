//Editorial: https://youtu.be/Mo33MjjMlyA
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt=0,cnt=0;
        for(auto it:nums)
        {
            if(it==1)
            {
                cnt+=1;
                maxcnt=max(maxcnt,cnt);
            }
            else
                cnt=0;
        }
        return maxcnt;
    }
};
