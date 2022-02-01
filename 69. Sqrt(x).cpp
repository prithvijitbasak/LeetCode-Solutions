//Editorial: https://leetcode.com/problems/sqrtx/discuss/553452/C++-Binary-Search-Approach-Runtime:-0ms-Faster-than-100
class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x;
        int ans;
        while(low<=high)
        {
            unsigned long long int mid=(low+high)>>1;
            unsigned long long int power=mid*mid;
            if(power==x)
                return mid;   
            if(power<x)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};
