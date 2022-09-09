//Editorial: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C++-solution-with-great-explanation-and-comments-(nlogn)-sorting
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int ans=0;
        int mtn=INT_MIN;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i][1]<mtn)
                ans+=1;
            mtn=max(mtn,nums[i][1]);
        }
        return ans;
    }
};
