//Editorial: https://leetcode.com/problems/third-maximum-number/discuss/90240/Short-Clear-C++-solution-no-set-or-pq.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int a=LLONG_MIN,b=LLONG_MIN,c=LLONG_MIN;
        for(auto it:nums)
        {
            if(it<=c or it==a or it==b)
                continue;
            c=it;
            if(c>b)
                swap(b,c);
            if(b>a)
                swap(a,b);
        }
        if(c==LLONG_MIN)
            return a;
        else
            return c;
    }
};
