//Editorial: https://leetcode.com/problems/sum-of-square-numbers/solution/
class Solution {
public:
    bool binary_search(long low,long high,long n)
    {
        if(low>high)
            return false;
        long mid=low+(high-low)/2;
        if(mid*mid==n)
            return true;
        if(mid*mid>n)
            return binary_search(low,mid-1,n);
        return binary_search(mid+1,high,n);
    }
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++)
        {
            int b=c-(int)a*a;
            if(binary_search(0,b,b))
                return true;
        }
        return false;
    }
};
