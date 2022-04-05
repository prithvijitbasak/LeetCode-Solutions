//Approach 1: Using counting sort. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/discuss/877736/c%2B%2B-use-counting-sort-0ms
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> freq(1004,0);
        for(int i=0;i<n;i++)
            freq[nums[i]]+=1;
        int ans=0;
        int curr=0;
        for(int i=mx;i>=1;i--)
        {
            curr+=freq[i];
            if(curr==i)
                return i;
        }
        return -1;
    }
};
//Approach 2: Using binary search. TC: O(nlogn) SC: O(1)
//Editorial: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/discuss/1295326/C%2B%2B-Solution-Using-Binary-Search-O(n*log1000)-Time-and-O(1)-Space
class Solution {
public:
    int solve(vector<int> &nums,int mid)
    {
        int cnt=0;
        for(auto it:nums)
        {
            if(it>=mid)
                cnt+=1;
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=solve(nums,mid);
            if(ans==mid)
                return mid;
            else if(ans<mid)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
};
