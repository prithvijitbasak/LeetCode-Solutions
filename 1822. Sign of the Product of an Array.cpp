//Editorial: https://leetcode.com/problems/sign-of-the-product-of-an-array/discuss/1152555/Java-solution-0-ms-Seriously-why-we-need-2
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=1;
        for(auto it:nums)
        {
            if(it==0)
                return 0;
            if(it<0)
                sign=-sign;
        }
        return sign;
    }
};
