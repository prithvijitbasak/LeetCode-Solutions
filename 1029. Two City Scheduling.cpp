//Editorial: https://leetcode.com/problems/two-city-scheduling/discuss/667786/Java-or-C%2B%2B-or-Python3-or-With-detailed-explanation
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int ans=0;
        int n=costs.size()/2;
        vector<int> refund;
        for(auto it:costs)
        {
            ans+=it[0];
            refund.push_back(it[1]-it[0]); //actually we need this so that we can know how much we are saving by sending them to city a or city b.
        }
        sort(refund.begin(),refund.end());
        for(int i=0;i<n;i++)
            ans+=refund[i];
        return ans;
    }
};
