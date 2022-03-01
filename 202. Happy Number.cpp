//Editorial: https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
class Solution {
public:
    int giveres(int n)
    {
        int res=0;
        while(n)
        {
            res+=pow((n%10),2);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast=giveres(n),slow=n;
        while(slow!=fast)
        {
            slow=giveres(slow);
            fast=giveres(giveres(fast));
        }
        return slow==1;
    }
};
