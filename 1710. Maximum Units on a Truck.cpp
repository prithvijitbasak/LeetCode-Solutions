//Editorial: https://leetcode.com/problems/maximum-units-on-a-truck/discuss/1272564/Short-and-Easy-Solution-w-Explanation-or-Greedily-Select-Max-UnitsBox-Ratio
//Approach 1: Using sorting. TC: O(nlogn) SC: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int limit) {
        sort(nums.begin(),nums.end(), [](vector<int> &a,vector<int> &b){return a[1]>b[1];});
        int ans=0;
        for(auto it:nums)
        {
            int val=min(it[0],limit);
            ans+=val*it[1];
            limit-=val;
            if(!limit)
                break;
        }
        return ans;
    }
};
//Approach 2: Using counting sort. TC: O(n) SC: O(1000)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int limit) {
        vector<int> freq(1001);
        for(auto it:nums)
            freq[it[1]]+=it[0];
        int ans=0;
        for(int i=1000;i>=0 and limit>0;i--)
        {
            ans+=min(freq[i],limit)*i;
            limit-=freq[i];
        }
        return ans;
    }
};
