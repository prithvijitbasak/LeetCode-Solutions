//Editorial: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization/548495
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int leftsum=0;
        for(int i=0;i<k;i++)
            leftsum+=nums[i];
        int ans=leftsum;
        int rightsum=0;
        for(int i=0;i<k;i++)
        {
            rightsum+=nums[n-1-i];
            leftsum-=nums[k-1-i];
            ans=max(ans,rightsum+leftsum);
        }
        return ans;
    }
};
