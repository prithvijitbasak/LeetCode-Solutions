//Editorial: https://leetcode.com/problems/continuous-subarray-sum/discuss/679929/C++-Code-With-Comments , https://youtu.be/OKcrLfR-8mE
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int sum=0,n=nums.size();
        ump[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(k)
                sum%=k;
            if(ump.find(sum)!=ump.end())
            {
                if(i-ump[sum]>1)
                    return true;
            }
            else
                ump[sum]=i;
        }
        return false;
    }
};
