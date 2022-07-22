//Editorial: Just use 3 vectors to store the values. TC: O(n) SC: O(3n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int x) {
        vector<int> s,m,e;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<x)
                s.push_back(nums[i]);
            else if(nums[i]==x)
                m.push_back(nums[i]);
            else
                e.push_back(nums[i]);
        }
        vector<int> ans;
        for(auto it:s)
            ans.push_back(it);
        for(auto it:m)
            ans.push_back(it);
        for(auto it:e)
            ans.push_back(it);
        return ans;
    }
};
//Editorial: Use  pointers. TC: O(n) SC: O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0,same=0;
        for(auto it:nums)
        {
            if(it<pivot)
                ans[i++]=it;
            else if(it==pivot)
                same+=1;
        }
        while(same--)
            ans[i++]=pivot;
        for(auto it:nums)
        {
            if(it>pivot)
                ans[i++]=it;
        }
        return ans;
    }
};
