//Editorial: https://leetcode.com/problems/matchsticks-to-square/discuss/2270410/C++-clean-code-oror-backtracking-oror-commented
class Solution {
public:
    int a,b,c,d;
    bool solve(vector<int> &nums,int idx)
    {
        if(idx==nums.size())
        {
            if(a==0 and b==0 and c==0 and d==0)
                return true;
        }
        if(a>=nums[idx])
        {
            a-=nums[idx];
            if(solve(nums,idx+1))
                return true;
            a+=nums[idx];
        }
        if(b>=nums[idx])
        {
            b-=nums[idx];
            if(solve(nums,idx+1))
                return true;
            b+=nums[idx];
        }
        if(c>=nums[idx])
        {
            c-=nums[idx];
            if(solve(nums,idx+1))
                return true;
            c+=nums[idx];
        }
        if(d>=nums[idx])
        {
            d-=nums[idx];
            if(solve(nums,idx+1))
                return true;
            d+=nums[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(n<4)
            return false;
        if(sum%4!=0)
            return false;
        sort(nums.rbegin(),nums.rend());
        a=b=c=d=sum/4;
        return solve(nums,0);
        
    }
};
