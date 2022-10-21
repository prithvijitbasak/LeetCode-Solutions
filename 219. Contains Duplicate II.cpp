//Editorial: https://leetcode.com/problems/contains-duplicate-ii/discuss/61390/C++-solution-with-unordered_set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> ust;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>k)
                ust.erase(nums[i-k-1]);
            if(ust.find(nums[i])!=ust.end())
                return true;
            ust.insert(nums[i]);
        }
        return false;
    }
};
