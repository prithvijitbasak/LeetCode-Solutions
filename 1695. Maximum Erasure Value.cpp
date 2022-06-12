//Editorial: https://leetcode.com/problems/maximum-erasure-value/discuss/978552/Java-O(n)-Sliding-Window-+-HashSet
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> st;
        int n=nums.size();
        int i=0,j=0;
        int ans=0,sum=0;
        while(i<n and j<n)
        {
            if(st.find(nums[j])==st.end())
            {
                sum+=nums[j];
                ans=max(ans,sum);
                st.insert(nums[j]);
                j++;
            }
            else
            {
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};
