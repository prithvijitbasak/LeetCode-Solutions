//Editorial: https://youtu.be/Q1TYVUEr-wY
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,maxstsum=INT_MIN,minstsum=INT_MAX,tempminsum=0,tempmaxsum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            tempmaxsum+=nums[i];
            maxstsum=max(maxstsum,tempmaxsum);
            tempmaxsum=max(tempmaxsum,0);
            tempminsum+=nums[i];
            minstsum=min(minstsum,tempminsum);
            tempminsum=min(tempminsum,0);
        }
        if(sum==minstsum)
            return maxstsum;
        return max(maxstsum,(sum-minstsum));
    }
};
