//Editorial: https://youtu.be/eMSfBgbiEjk
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minprice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minprice=min(prices[i],minprice);
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};
