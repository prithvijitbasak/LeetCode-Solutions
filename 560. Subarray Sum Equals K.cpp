//Editorial: https://leetcode.com/problems/subarray-sum-equals-k/discuss/102121/C%2B%2B-prefix-sum-%2B-map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        ump[0]++;
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(ump.find(sum-k)!=ump.end())
                cnt+=ump[sum-k];
            ump[sum]++;
        }
        return cnt;
    }
};
