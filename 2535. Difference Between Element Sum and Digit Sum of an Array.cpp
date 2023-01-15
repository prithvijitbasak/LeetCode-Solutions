//Editorial: Just iterate over the array and sum up the values and find the sum of digits of  every values to find the  answer.
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int digsum=0;
        for(auto it:nums)
        {
            int temp=it;
            while(temp)
            {
                digsum+=(temp%10);
                temp/=10;
            }
        }
        return abs(sum-digsum);
    }
};
