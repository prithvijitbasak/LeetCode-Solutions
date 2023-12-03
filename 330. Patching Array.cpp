//Editorial: https://leetcode.com/problems/patching-array/solutions/78492/c-8ms-greedy-solution-with-explanation/
class Solution {
public:
    typedef long long ll;
    int minPatches(vector<int>& nums, int target) {
        // tutorial : https://leetcode.com/problems/patching-array/solutions/78492/c-8ms-greedy-solution-with-explanation/
        ll n = nums.size(); 
        ll ans = 0;
        ll maxVal = 0;
        ll i = 0;
        while(maxVal < target)
        {
            if(i<n and nums[i] <= maxVal + 1)
            {                
                maxVal += nums[i];
                i += 1;
            }
            else
            {
                maxVal += maxVal + 1;
                ans += 1;
            }
        }
        return ans;
    }
};
