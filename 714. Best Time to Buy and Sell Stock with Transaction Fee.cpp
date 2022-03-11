//Editorial: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=-prices[0];
        int cash=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            cash=max(cash,hold+prices[i]-fee);
            hold=max(hold,cash-prices[i]);
        }
        return cash;
    }
};
