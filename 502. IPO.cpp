//Editorial: https://leetcode.com/problems/ipo/solutions/2959870/ipo/?orderBy=most_votes
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> nums;
        int n=profits.size();
        for(int i=0;i<n;i++)
            nums.push_back({capital[i],profits[i]});
        sort(nums.begin(),nums.end());
        priority_queue<int> pq;
        int j=0;
        for(int i=0;i<k;i++)
        {
            while(j<n and nums[j].first<=w)
            {
                pq.push(nums[j].second);
                j+=1;
            }
            if(pq.empty())
                break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};
