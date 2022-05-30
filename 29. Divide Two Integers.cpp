//Editorial: https://leetcode.com/problems/divide-two-integers/discuss/13467/Very-detailed-step-by-step-explanation-(Java-solution)
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isneg=((dividend<0 and divisor>0) or (dividend>0 and divisor<0))?true:false;
        long long absdividend=abs(dividend);
        long long absdivisor=abs(divisor);
        long long temp=0,cnt=0,ans=0;
        while(absdividend>=absdivisor)
        {
            temp=absdivisor,cnt=1;
            while(temp<=absdividend)
            {
                temp<<=1;
                cnt<<=1;
            }
            ans+=(cnt>>1);
            absdividend-=(temp>>1);
        }
        if(isneg)
            return -ans;
        else
        {
            if(ans>INT_MAX)
                return INT_MAX;
            else
                return (int)ans;
        }
    }
};
