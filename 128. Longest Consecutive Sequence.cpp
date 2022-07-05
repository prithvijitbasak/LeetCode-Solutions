//Editorial: https://leetcode.com/problems/longest-consecutive-sequence/solution/
//Approach 1: Using sorting. TC: O(nlogn) SC: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int ls=0,cs=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1)
                cs+=1;
            else
            {
                ls=max(ls,cs);
                cs=1;
            }
        }
        return max(ls,cs);
}
};
//Approach 2: Using hashset TC: O(n) SC; O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(auto it:nums)
            st.insert(it);
        int ans=0;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int currnum=it;
                int currstreak=1;
                while(st.find(currnum+1)!=st.end())
                {
                    currnum+=1;
                    currstreak+=1;
                }
                ans=max(ans,currstreak);
            }
        }
        return ans;
    }
};
