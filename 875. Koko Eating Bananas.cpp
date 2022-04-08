//Editorial: https://leetcode.com/problems/koko-eating-bananas/solution/
class Solution {
public:
    bool solve(vector<int> &piles,int h,int k)
    {
        int totaltime=0;
        for(auto it:piles)
            totaltime+=(it/k)+(it%k!=0);
        if(totaltime>h)
            return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(solve(piles,h,mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
