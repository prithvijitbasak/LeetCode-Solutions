//Editorial: https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268472/C++-Binary-Answer
class Solution {
public:
    vector<int> removed;
    bool valid(vector<int> nums,int mid,string s,string p)
    {
        removed.assign(1e5+1,0);
        for(int i=0;i<mid;i++)
            removed[nums[i]]=1;
        int n=s.size(),m=p.size();
        int j=0;
        for(int i=0; i<n and j<m;i++)
        {
            if(removed[i]==1)
                continue;
            if(s[i]==p[j])
                j++;
        }
        if(j==m)
            return true;
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& nums) {
        int n=size(nums);
        int low=0,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(nums,mid,s,p))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};
