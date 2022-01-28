//Editorial: https://youtu.be/muDPTDrpS28
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxsteps=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mxsteps<i)
                return false;
            mxsteps=max(mxsteps,i+nums[i]);
        }
        return true;
    }
};
