//Editorial: https://leetcode.com/problems/house-robber-ii/discuss/59934/Simple-AC-solution-in-Java-in-O(n)-with-explanation/61006
class Solution {
public:
    int rob1(vector<int> &nums)
    {
        int premax=0,currmax=0;
        for(int i=1;i<nums.size();i++)
        {
            int temp=currmax;
            currmax=max(premax+nums[i],currmax);
            premax=temp;
        }
        return currmax;
    }
    int rob2(vector<int> &nums)
    {
        int premax=0,currmax=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            int temp=currmax;
            currmax=max(premax+nums[i],currmax);
            premax=temp;
        }
        return currmax;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(rob1(nums),rob2(nums));
    }
};
