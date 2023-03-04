//Editorial: https://leetcode.com/problems/product-of-array-except-self/solutions/1597994/c-python-4-simple-solutions-w-explanation-prefix-suffix-product-o-1-space-approach/?orderBy=most_votes
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        zero=count(nums.begin(),nums.end(),0);
        if(zero>1)
            return vector<int> (n,0);
        int prod=1;
        for(auto it:nums)
        {
            if(it)
                prod*=it;
        }
        for(int i=0;i<n;i++)
        {
            if(zero)
            {
                if(nums[i])
                    nums[i]=0;
                else
                    nums[i]=prod;
            }
            else
                nums[i]=prod/nums[i];
        }
        return nums;
    }
};
