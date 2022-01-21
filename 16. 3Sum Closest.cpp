//Editorial: https://leetcode.com/problems/3sum-closest/discuss/1042348/Faster-solution-about-95-faster-and-easy-solution-with-comments
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int inisum=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int tempsum=nums[i]+nums[j]+nums[k];
                if(abs(tempsum-target)<abs(inisum-target))
                    inisum=tempsum;
                if(tempsum>target)
                    k--;
                else if(tempsum<target)
                    j++;
                else
                    return target;
            }
        }
        return inisum;
    }
};
