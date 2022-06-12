//Editorial: https://leetcode.com/problems/calculate-amount-paid-in-taxes/discuss/2140963/C++-oror-Calculate-Amount-Paid-in-Taxes-oror-Math-TC-O(N)
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans=0.0;
        if(income==0)
            return 0;
        int prev=0;
        int n=brackets.size();
        for(int i=0;i<n;i++)
        {
            int actual=min(brackets[i][0],income);
            ans+=((actual-prev)*brackets[i][1])/100.0;
            if(brackets[i][0]>=income)
                break;
            prev=brackets[i][0];
        }
        return ans;
    }
};
